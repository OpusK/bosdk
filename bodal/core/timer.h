#ifndef BOSDK_BODAL_CORE_TIMER_H_
#define BOSDK_BODAL_CORE_TIMER_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_TIMER)

bool timerInit(void);

void timerStop(uint8_t channel);
void timerSetPeriod(uint8_t channel, uint32_t period_data);
void timerAttachInterrupt(uint8_t channel, voidFuncPtr handler);
void timerDetachInterrupt(uint8_t channel);
void timerStart(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_TIMER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_TIMER_H_ */
