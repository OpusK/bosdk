#ifndef BOSDK_BODAL_DRIVER_DELAY_H_
#define BOSDK_BODAL_DRIVER_DELAY_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_DELAY)

#include <stdint.h>

void delayInit();

void delay(uint32_t ms);
//void delay_ns(uint32_t ns);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_DELAY */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_DELAY_H_ */
