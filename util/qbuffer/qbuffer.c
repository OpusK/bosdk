#include "qbuffer.h"

#if(BOSDK_ENABLE_UTIL_QBUFFER)

#include <stdlib.h>


bosdk_err_t qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length)
{
  bosdk_err_t err_code = BOSDK_OK;

  p_node->ptr_in  = 0;
  p_node->ptr_out = 0;
  p_node->length  = length;
  p_node->p_buf   = p_buf;

  if (p_node->p_buf == NULL)
  {
    p_node->length = 0;
    err_code = BOSDK_ERR_MEMORY;
  }

  return err_code;
}

uint32_t qbufferAvailable(qbuffer_t *p_node)
{
  return (p_node->length + p_node->ptr_in - p_node->ptr_out) % p_node->length;
}

bosdk_err_t qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
{
  bosdk_err_t err_code = BOSDK_OK;
  uint32_t index;
  uint32_t next_index;
  uint32_t i;

  if (p_node->p_buf == NULL) return BOSDK_ERR_NULL;


  for (i=0; i<length; i++)
  {
    index      = p_node->ptr_in;
    next_index = p_node->ptr_in + 1;

    if (next_index == p_node->length)
    {
      next_index = 0;;
    }

    if (next_index != p_node->ptr_out)
    {
      p_node->p_buf[index] = p_data[i];
      p_node->ptr_in       = next_index;
    }
    else
    {
      err_code = BOSDK_ERR_FULL;
      break;
    }
  }

  return err_code;
}

bosdk_err_t qbufferWriteByte(qbuffer_t *p_node, uint8_t data)
{
  return qbufferWrite(p_node, &data, 1);
}

bosdk_err_t qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
{
  bosdk_err_t err_code = BOSDK_OK;
  uint32_t index;
  uint32_t next_index;
  uint32_t i;

  if (p_node->p_buf == NULL) return BOSDK_ERR_NULL;

  for (i=0; i<length; i++)
  {
    index      = p_node->ptr_out;
    next_index = p_node->ptr_out + 1;

    if (next_index == p_node->length)
    {
      next_index = 0;
    }

    if (index != p_node->ptr_in)
    {
      p_data[i]       = p_node->p_buf[index];
      p_node->ptr_out = next_index;
    }
    else
    {
      err_code = BOSDK_ERR_EMPTY;
      break;
    }
  }


  return err_code;
}

void qbufferFlush(qbuffer_t *p_node)
{
  p_node->ptr_in  = 0;
  p_node->ptr_out = 0;
}


#endif /* BOSDK_ENABLE_UTIL_QBUFFER */
