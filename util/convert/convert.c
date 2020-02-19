#include "convert.h"

uint32_t convertU8arrayToU32 (uint8_t *p_data)
{
  uint32_t t_data = 0;
  uint8_t i;

  for(i = 0; i < 4; i++)
  {
    t_data |= p_data[i] << (i*8);
  }

  return t_data;
}

uint16_t convertU8arrayToU16 (uint8_t *p_data)
{
  uint16_t t_data = 0;
  uint8_t i;

  for(i = 0; i < 2; i++)
  {
    t_data |= p_data[i] << (i*8);
  }

  return t_data;
}

