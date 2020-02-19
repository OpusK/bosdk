#ifndef BOSDK_UTIL_H_
#define BOSDK_UTIL_H_


#ifdef __cplusplus
 extern "C" {
#endif

//Utility Headers
#include "bootcmd/bootcmd.h"
#include "cmd/cmd.h"
#include "cmdif/cmdif.h"
#include "convert/convert.h"
#include "ctable/ctable.h"
#include "qbuffer/qbuffer.h"
#include "ring/ring.h"


#define PI              3.1415926535897932384626433832795
#define HALF_PI         1.5707963267948966192313216916398
#define TWO_PI          6.283185307179586476925286766559
#define DEG_TO_RAD      0.017453292519943295769236907684886
#define RAD_TO_DEG      57.295779513082320876798154814105
#define EULER           2.718281828459045235360287471352

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifndef max
#define max(a,b) (((a) (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef map
#define map(value, in_min, in_max, out_min, out_max) ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif

#ifndef byte
#define byte uint8_t
#endif

#ifndef sq
#define sq(x) ((x)*(x))
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  uint32_t range_start;
  uint32_t range_end;

  uint32_t node_addr_start;
  uint32_t node_addr_end;
  uint32_t node_length;
  uint32_t node_byte_index;
} data_range_t;

bool utilGetRange(data_range_t *p_range);

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_H_ */
