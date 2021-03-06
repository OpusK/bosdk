#ifndef BOSDK_UTIL_CMD_H
#define BOSDK_UTIL_CMD_H


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_UTIL_CMD)

#include <stdint.h>
#include <stdbool.h>

#define BOSDK_CMD_MAX_DATA_LENGTH       _HW_DEF_CMD_MAX_DATA_LENGTH

typedef struct
{
  uint32_t index;
  uint8_t  cmd;
  uint16_t option;
  uint16_t error;
  uint16_t length;
  uint8_t  check_sum;
  uint8_t  check_sum_recv;
  uint8_t  data[BOSDK_CMD_MAX_DATA_LENGTH];
} cmd_packet_t;


typedef struct
{
  uint8_t  ch;
  uint8_t  init;
  uint8_t  state;
  uint32_t baud;
  uint32_t save_time[2];
  uint16_t packet_err;

  tx_packet;
  rx_packet;
} cmd_t;



void cmdInit(cmd_t *p_cmd);

void cmdBegin(cmd_t *p_cmd, uint8_t ch, uint32_t baud);
bool cmdReceivePacket(cmd_t *p_cmd);
void cmdSendCmd(cmd_t *p_cmd, uint8_t cmd, uint8_t *p_data, uint32_t length);
void cmdSendResp(cmd_t *p_cmd, uint16_t err_code, uint8_t *p_data, uint32_t length);
void cmdFlush(cmd_t *p_cmd);

#endif /* BOSDK_ENABLE_UTIL_CMD */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_CMD_H */
