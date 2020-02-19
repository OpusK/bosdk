#ifndef BOSDK_BODAL_DRIVER_MICROS_H_
#define BOSDK_BODAL_DRIVER_MICROS_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_MICROS)

#include <stdint.h>
#include <stdbool.h>

bool microsInit(void);
uint32_t micros(void);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_MICROS */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_MICROS_H_ */
