#ifndef BOSDK_UTIL_RING_H
#define BOSDK_UTIL_RING_H


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_UTIL_RING)

#include <stdint.h>
#include <stdbool.h>
#include "../../error_code.h"

typedef struct
{
  bosdk_err_t err_code;
  uint32_t   ptr_in;
  uint32_t   ptr_out;
  uint32_t   length;
} ring_node_t;



bool ringInit(void);

bosdk_err_t ringCreate(ring_node_t *p_node, uint32_t length);

bosdk_err_t ringWriteUpdate(ring_node_t *p_node);
uint32_t   ringWriteAvailable(ring_node_t *p_node);
uint32_t   ringGetWriteIndex(ring_node_t *p_node);

bosdk_err_t ringReadUpdate(ring_node_t *p_node);
uint32_t   ringReadAvailable(ring_node_t *p_node);
uint32_t   ringGetReadIndex(ring_node_t *p_node);
uint32_t   ringGetReadOffsetIndex(ring_node_t *p_node, uint32_t offset);

bosdk_err_t ringFlush(ring_node_t *p_node);

#endif /* BOSDK_ENABLE_UTIL_RING */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_RING_H */
