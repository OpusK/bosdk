#ifndef BOSDK_BODAL_DRIVER_BUZZER_H_
#define BOSDK_BODAL_DRIVER_BUZZER_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_BUZZER)

#include <stdint.h>
#include <stdbool.h>

bool buzzerInit(void);

void buzzerOn(uint32_t freq, uint32_t time);
void buzzerOff(void);

void buzzerAddPeriod(int32_t period);

void buzzerStop(void);
void buzzerStart(void);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_BUZZER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_BUZZER_H_ */
