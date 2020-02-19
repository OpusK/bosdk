#ifndef BOSDK_BODAL_DRIVER_MILLIS_H_
#define BOSDK_BODAL_DRIVER_MILLIS_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_MILLIS)

bool millisInit(void);
uint32_t millis(void);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_MILLIS */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_MILLIS_H_ */
