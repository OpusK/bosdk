#include "bootcmd.h"

#if(BOSDK_ENABLE_UTIL_BOOTCMD)

#include "../convert/convert.h"

#define BOOT_ERR_INVAILD_CMD            0xF0F0

#define BOOT_CMD_READ_VERSION           0x00
#define BOOT_CMD_PACKET_DATA_SIZE_MAX   0x01
#define BOOT_CMD_READ_BOARD_NAME        0x02
#define BOOT_CMD_FLASH_ERASE            0x03
#define BOOT_CMD_FLASH_WRITE            0x04
#define BOOT_CMD_FLASH_READ             0x05
#define BOOT_CMD_FLASH_VERIFY           0x06
#define BOOT_CMD_JUMP                   0x07


static void bootcmdUpdateCrc(uint16_t *p_crc_cur, uint8_t data_in);

static void bootCmdReadVersion(cmd_t *p_cmd);
static void bootCmdPacketDataSizeMax(cmd_t *p_cmd);
static void bootCmdReadBoardName(cmd_t *p_cmd);
static void bootCmdFlashErase(cmd_t *p_cmd);
static void bootCmdFlashWrite(cmd_t *p_cmd);
static void bootCmdFlashRead(cmd_t *p_cmd);
static void bootCmdJumpToAddress(cmd_t *p_cmd);
static void bootCmdFlashVerify(cmd_t *p_cmd);

void bootCmdInit(void)
{
}

bosdk_err_t checkFw(uint32_t type, uint32_t address)
{
  fw_tag_type_a_t *p_tag;
  uint8_t *p_data;
  uint32_t i;
  uint16_t crc = 0;

  /* Check Address */
  if(address < _HW_DEF_FLASH_ADDR_APP_START)
    return ERR_FLASH_INVALID_ADDR;

  if(type != *(uint32_t*) address)
    return ERR_FLASH_INVALID_TAG;

  /* Check Type & CRC16 */
  if(type == FW_TAG_TYPE_A)
  {
    p_tag = (fw_tag_type_a_t*) (address);
    p_data = (uint8_t*) p_tag->address;

    for (i = 0; i < p_tag->length; i++)
    {
      utilUpdateCrc(&crc, p_data[i]);
    }

    if(crc != p_tag->crc)
    {
      return ERR_FLASH_CRC;
    }
  }
  else
  {
    return ERR_FLASH_INVALID_TAG;
  }

  return OK;
}

void bootCmdReadVersion(cmd_t *p_cmd)
{
  uint8_t data[8] = {0, };
  uint32_t i = 0;

  data[i++] = ((uint8_t *) _HW_DEF_FLASH_ADDR_BOOT_VER_NUM)[0];
  data[i++] = ((uint8_t *) _HW_DEF_FLASH_ADDR_APP_VER_NUM)[0];

  cmdSendResp(p_cmd, OK, data, i);
}

void bootCmdPacketDataSizeMax(cmd_t *p_cmd)
{
  uint8_t data[8] = {0, };
  uint16_t t_size = (uint16_t) CMD_MAX_DATA_LENGTH;
  uint32_t i = 0;

  data[i++] = (uint8_t) t_size;
  data[i++] = (uint8_t) (t_size >> 8);

  cmdSendResp(p_cmd, OK, data, i);
}

void bootCmdReadBoardName(cmd_t *p_cmd)
{
  cmdSendResp(p_cmd, OK, (uint8_t*)_BSP_DEF_BOARD_NAME, strlen((char *)_BSP_DEF_BOARD_NAME)+1);
}

void bootCmdFlashErase(cmd_t *p_cmd)
{
  bosdk_err_t err_code = OK;
  uint32_t addr_begin;
  uint32_t addr_end;
  uint32_t length;

  addr_begin = convertU8arrayToU32(&p_cmd->rx_packet.data[0]);
  length     = convertU8arrayToU32(&p_cmd->rx_packet.data[4]);
  addr_end   = addr_begin + length - 1;

  if ((addr_begin >= _HW_DEF_FLASH_ADDR_APP_START)
      && (addr_end < _HW_DEF_FLASH_ADDR_APP_END))
  {
    if (addr_begin % 4 == 0)
    {
      err_code = flashErase(addr_begin, length);
    }
    else
    {
      err_code = ERR_FLASH_ADDR_ALIGN;
    }
  }
  else
  {
    err_code = ERR_FLASH_INVALID_ADDR;
  }

  cmdSendResp(p_cmd, err_code, NULL, 0);

}

void bootCmdFlashWrite(cmd_t *p_cmd)
{
  bosdk_err_t err_code = OK;
  uint32_t addr_begin;
  uint32_t addr_end;
  uint32_t length;
  uint8_t *p_flash, *p_data;

  addr_begin = convertU8arrayToU32(&p_cmd->rx_packet.data[0]);
  length     = convertU8arrayToU32(&p_cmd->rx_packet.data[4]);
  addr_end   = addr_begin + length - 1;

  if ((addr_begin >= _HW_DEF_FLASH_ADDR_APP_START)
      && (addr_end < _HW_DEF_FLASH_ADDR_APP_END))
  {
    if (addr_begin % 4 == 0)
    {
      err_code = flashWrite(addr_begin, &p_cmd->rx_packet.data[8], length);
    }
    else
    {
      err_code = ERR_FLASH_ADDR_ALIGN;
    }
  }
  else
  {
    err_code = ERR_FLASH_INVALID_ADDR;
  }

  if(err_code == OK)
  {
    p_flash = (uint8_t*) addr_begin;
    p_data  = &p_cmd->rx_packet.data[8];
    for(uint32_t i=0; i<length; i++)
    {
      if(p_flash[i] != p_data[i])
      {
        err_code = ERR_FLASH_WRITE;
        break;
      }
    }
  }

  cmdSendResp(p_cmd, err_code, NULL, 0);
}

void bootCmdFlashRead(cmd_t *p_cmd)
{
  bosdk_err_t err_code = OK;
  uint32_t addr_begin;
  uint32_t length;
  uint32_t i;
  uint8_t *p_data;

  addr_begin = convertU8arrayToU32(&p_cmd->rx_packet.data[0]);
  length     = convertU8arrayToU32(&p_cmd->rx_packet.data[4]);

  if (length > sizeof(p_cmd->tx_packet.data))
  {
    err_code = ERR_INVALID_LENGTH;
  }
  else
  {
    p_data = (uint8_t *) addr_begin;
    for (i = 0; i < length; i++)
    {
      p_cmd->tx_packet.data[i] = p_data[i];
    }
  }

  if (err_code == OK)
  {
    cmdSendResp(p_cmd, err_code, p_cmd->tx_packet.data, length);
  }
  else
  {
    cmdSendResp(p_cmd, err_code, NULL, 0);
  }
}

void bootCmdFlashVerify(cmd_t *p_cmd)
{
  bosdk_err_t err_code = OK;
  uint32_t addr_begin;
  uint32_t length;
  uint16_t rx_crc;
  uint16_t tx_crc = 0;
  uint8_t *p_data;
  uint32_t i;

  addr_begin = convertU8arrayToU32(&p_cmd->rx_packet.data[0]);
  length     = convertU8arrayToU32(&p_cmd->rx_packet.data[4]);
  rx_crc     = convertU8arrayToU16(&p_cmd->rx_packet.data[8]);
  p_data     = (uint8_t *) addr_begin;

  for (i = 0; i < length; i++)
  {
    utilUpdateCrc(&tx_crc, p_data[i]);
  }

  if(tx_crc != rx_crc)
  {
    err_code = ERR_FLASH_CRC;
  }

  cmdSendResp(p_cmd, err_code, (uint8_t *)&tx_crc, 2);
}

void bootCmdJumpToAddress(cmd_t *p_cmd)
{
  uint32_t address = convertU8arrayToU32(&p_cmd->rx_packet.data[0]);

  bosdk_err_t err = checkFw(FW_TAG_TYPE_A, address);

  cmdSendResp(p_cmd, err, NULL, 0);
  if(err == OK)
  {
    fw_tag_type_a_t *p_tag = (fw_tag_type_a_t*) (address);
    delay(100);
    bspJumpToAddress(p_tag->address);
  }
}

void bootCmdProcess(cmd_t *p_cmd)
{
  switch (p_cmd->rx_packet.cmd)
  {
    case BOOT_CMD_READ_VERSION:
      bootCmdReadVersion(p_cmd);
      break;

    case BOOT_CMD_PACKET_DATA_SIZE_MAX:
      bootCmdPacketDataSizeMax(p_cmd);
      break;

    case BOOT_CMD_READ_BOARD_NAME:
      bootCmdReadBoardName(p_cmd);
      break;

    case BOOT_CMD_FLASH_ERASE:
      bootCmdFlashErase(p_cmd);
      break;

    case BOOT_CMD_FLASH_WRITE:
      bootCmdFlashWrite(p_cmd);
      break;

    case BOOT_CMD_FLASH_READ:
      bootCmdFlashRead(p_cmd);
      break;

    case BOOT_CMD_FLASH_VERIFY:
      bootCmdFlashVerify(p_cmd);
      break;

    case BOOT_CMD_JUMP:
      bootCmdJumpToAddress(p_cmd);
      break;

    default:
      cmdSendResp(p_cmd, BOOT_ERR_INVAILD_CMD, NULL, 0);
      break;
  }
}




volatile const unsigned short bootcmd_crc_table[256] = {0x0000,
                                0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
                                0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027,
                                0x0022, 0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D,
                                0x8077, 0x0072, 0x0050, 0x8055, 0x805F, 0x005A, 0x804B,
                                0x004E, 0x0044, 0x8041, 0x80C3, 0x00C6, 0x00CC, 0x80C9,
                                0x00D8, 0x80DD, 0x80D7, 0x00D2, 0x00F0, 0x80F5, 0x80FF,
                                0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1, 0x00A0, 0x80A5,
                                0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1, 0x8093,
                                0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
                                0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197,
                                0x0192, 0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE,
                                0x01A4, 0x81A1, 0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB,
                                0x01FE, 0x01F4, 0x81F1, 0x81D3, 0x01D6, 0x01DC, 0x81D9,
                                0x01C8, 0x81CD, 0x81C7, 0x01C2, 0x0140, 0x8145, 0x814F,
                                0x014A, 0x815B, 0x015E, 0x0154, 0x8151, 0x8173, 0x0176,
                                0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162, 0x8123,
                                0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
                                0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104,
                                0x8101, 0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D,
                                0x8317, 0x0312, 0x0330, 0x8335, 0x833F, 0x033A, 0x832B,
                                0x032E, 0x0324, 0x8321, 0x0360, 0x8365, 0x836F, 0x036A,
                                0x837B, 0x037E, 0x0374, 0x8371, 0x8353, 0x0356, 0x035C,
                                0x8359, 0x0348, 0x834D, 0x8347, 0x0342, 0x03C0, 0x83C5,
                                0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1, 0x83F3,
                                0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
                                0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7,
                                0x03B2, 0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E,
                                0x0384, 0x8381, 0x0280, 0x8285, 0x828F, 0x028A, 0x829B,
                                0x029E, 0x0294, 0x8291, 0x82B3, 0x02B6, 0x02BC, 0x82B9,
                                0x02A8, 0x82AD, 0x82A7, 0x02A2, 0x82E3, 0x02E6, 0x02EC,
                                0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2, 0x02D0, 0x82D5,
                                0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1, 0x8243,
                                0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
                                0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264,
                                0x8261, 0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E,
                                0x0234, 0x8231, 0x8213, 0x0216, 0x021C, 0x8219, 0x0208,
                                0x820D, 0x8207, 0x0202 };

void bootcmdUpdateCrc(uint16_t *p_crc_cur, uint8_t data_in)
{
  uint16_t crc;
  uint16_t i;

  crc = *p_crc_cur;

  i = ((unsigned short)(crc >> 8) ^ data_in) & 0xFF;
  *p_crc_cur = (crc << 8) ^ bootcmd_crc_table[i];
}


#endif /* BOSDK_ENABLE_UTIL_BOOTCMD */

