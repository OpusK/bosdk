#ifndef BOSDK_BODAL_DRIVER_BUTTON_H_
#define BOSDK_BODAL_DRIVER_BUTTON_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_BUTTON)

#include <stdint.h>
#include <stdbool.h>

#define  BODAL_BUTTON_MAX_CH    HW_BUTTON_MAX_CH

bool     buttonInit(void);
void     buttonEnable(bool enable);
void     buttonResetTime(uint8_t channel);
bool     buttonGetPressed(uint8_t channel);
bool     buttonGetPressedEvent(uint8_t channel);
uint32_t buttonGetPressedTime(uint8_t channel);

bool     buttonGetReleased(uint8_t channel);
bool     buttonGetReleasedEvent(uint8_t channel);
uint32_t buttonGetReleasedTime(uint8_t channel);

bool     buttonOsdGetPressed(uint8_t ch);

#endif  /* BOSDK_ENABLE_BODAL_DRIVER_BUTTON */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_BUTTON_H_ */
