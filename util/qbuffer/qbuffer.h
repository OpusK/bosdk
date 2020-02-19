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
  uint8_t   *p_buf;
} qbuffer_node_t;



bool qbufferInit(void);
bosdk_err_t qbufferCreate(qbuffer_node_t *p_node, uint32_t length);
uint32_t   qbufferAvailable(qbuffer_node_t *p_node);
bosdk_err_t qbufferWrite(qbuffer_node_t *p_node, uint8_t *p_data, uint32_t length);
bosdk_err_t qbufferWriteByte(qbuffer_node_t *p_node, uint8_t data);
bosdk_err_t qbufferRead(qbuffer_node_t *p_node, uint8_t *p_data, uint32_t length);
bosdk_err_t qbufferReadByte(qbuffer_node_t *p_node, uint8_t *p_data);

#endif /* BOSDK_ENABLE_UTIL_QBUFFER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_QBUFFER_H */
