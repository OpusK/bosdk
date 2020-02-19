#ifndef BOSDK_BODAL_CORE_GPIO_H_
#define BOSDK_BODAL_CORE_GPIO_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_GPIO)

#define BODAL_GPIO_MAX_CH     HW_GPIO_MAX_CH

bool gpioInit(void);
void gpioPinMode(uint8_t channel, uint8_t mode);
void gpioPinWrite(uint8_t channel, uint8_t value);
void    gpioPinToggle(uint8_t channel);
uint8_t gpioPinRead(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_GPIO */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_GPIO_H_ */
