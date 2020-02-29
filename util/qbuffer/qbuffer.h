#ifndef BOSDK_UTIL_QBUFFER_H
#define BOSDK_UTIL_QBUFFER_H


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_UTIL_QBUFFER)

#include <stdint.h>
#include <stdbool.h>
#include "../../error_code.h"

typedef struct
{
  bosdk_err_t err_code;
  uint32_t   ptr_in;
  uint32_t   ptr_out;
  uint32_t   length;
  uint8_t    *p_buf;
} qbuffer_t;


bosdk_err_t qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length);
uint32_t    qbufferAvailable(qbuffer_t *p_node);
bosdk_err_t qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
bosdk_err_t qbufferWriteByte(qbuffer_t *p_node, uint8_t data);
bosdk_err_t qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
void        qbufferFlush(qbuffer_t *p_node);

#endif /* BOSDK_ENABLE_UTIL_QBUFFER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_QBUFFER_H */
