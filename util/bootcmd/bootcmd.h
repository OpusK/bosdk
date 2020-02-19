#ifndef BOSDK_UTIL_BOOTCMD_H
#define BOSDK_UTIL_BOOTCMD_H


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_UTIL_BOOTCMD)

#include <stdint.h>
#include <stdbool.h>
#include "../../error_code.h"

#define FW_TAG_TYPE_A 0

typedef struct
{
  uint32_t type;
  uint32_t address;
  uint32_t length;
  uint16_t crc;
} fw_tag_type_a_t;


void bootCmdInit(void);
void bootCmdProcess(cmd_t *p_cmd);
bosdk_err_t checkFw(uint32_t type, uint32_t address);


#endif /* BOSDK_ENABLE_UTIL_BOOTCMD */


#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_BOOTCMD_H */
