#include "util.h"

bool utilGetRange(data_range_t *p_range)
{
  bool ret = false;


  p_range->node_byte_index = 0;

  if (p_range->node_addr_start >= p_range->range_start && p_range->node_addr_end <= p_range->range_end)
  {
    ret = true;
  }
  if (p_range->range_start >= p_range->node_addr_start && p_range->range_start < p_range->node_addr_end)
  {
    ret = true;
    p_range->node_byte_index = p_range->range_start - p_range->node_addr_start;
    p_range->node_addr_start = p_range->range_start;
  }
  if (p_range->range_end > p_range->node_addr_start && p_range->range_end <= p_range->node_addr_end)
  {
    ret = true;
    p_range->node_addr_end = p_range->range_end;
  }
  p_range->node_length = p_range->node_addr_end - p_range->node_addr_start;

  return ret;
}