#ifndef BOSDK_BODAL_CORE_PWM_H_
#define BOSDK_BODAL_CORE_PWM_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_PWM)

#define BODAL_PWM_MAX_CH            HW_PWM_MAX_CH

bool pwmInit(void);
bool pwmSetup(uint8_t channel, uint32_t freq);

void pwmSetDuty(uint8_t channel, uint8_t duty);
void pwmSetPulse(uint8_t channel, uint32_t res, uint32_t pulse);
uint8_t  pwmGetDuty(uint8_t channel);
uint32_t pwmGetPulse(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_PWM */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_PWM_H_ */
