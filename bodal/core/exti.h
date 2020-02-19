#ifndef BOSDK_BODAL_CORE_EXTI_H_
#define BOSDK_BODAL_CORE_EXTI_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_EXTI)

#define BODAL_EXTI_MAX_CHANNEL      HW_EXTI_MAX_CHANNEL

void extiInit(void);
bool extiAttachInterrupt(uint8_t channel, uint32_t mode, void (*func)(void *), void *arg);
void extiDetachInterrupt(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_EXTI */

#ifdef __cplusplus
 }
#endif


#endif /* BOSDK_BODAL_CORE_EXTI_H_ */
