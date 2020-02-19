#ifndef BOSDK_BODAL_DRIVER_LED_H_
#define BOSDK_BODAL_DRIVER_LED_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_LED)
#include <stdint.h>
#include <stdbool.h>

#define BODAL_LED_MAX_CH       HW_LED_MAX_CH

bool ledInit(void);
void ledOn(uint8_t channel);
void ledOff(uint8_t channel);
void ledToggle(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_LED */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_LED_H_ */
