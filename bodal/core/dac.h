#ifndef BOSDK_BODAL_CORE_DAC_H_
#define BOSDK_BODAL_CORE_DAC_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_DAC)

#include <stdbool.h>
#include <stdint.h>

#define BODAL_DAC_MAX_CHANNEL      HW_DAC_MAX_CHANNEL

void dacInit(void);
void dacClose(void);
bool dacSetup(uint32_t hz);
bool dacStart(uint8_t channel);
void dacStop(uint8_t channel);
void dacWrite(uint8_t channel, uint16_t data);
uint32_t dacAvailable(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_DAC */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_DAC_H_ */
