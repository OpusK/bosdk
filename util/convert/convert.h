#ifndef BOSDK_UTIL_CONVERT_H_
#define BOSDK_UTIL_CONVERT_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

#ifndef radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif
#ifndef degress
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif

uint32_t convertU8arrayToU32 (uint8_t *p_data);
uint16_t convertU8arrayToU16 (uint8_t *p_data);

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_UTIL_CONVERT_H_ */
