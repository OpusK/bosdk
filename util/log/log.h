#ifndef BOSDK_UTIL_LOG_H_
#define BOSDK_UTIL_LOG_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_UTIL_LOG)

#include <stdint.h>
#include <stdbool.h>

#define BOSDK_LOG_CH   HW_LOG_CH

bool logInit(void);

void logOn(uint8_t mode);
void logOff(uint8_t mode);
void logSetChannel(uint8_t ch);
void logPrintf(uint8_t mode, const char *fmt, ...);

#endif /* BOSDK_ENABLE_UTIL_LOG */

#ifdef __cplusplus
}
#endif



#endif /* BOSDK_UTIL_LOG_H_ */
