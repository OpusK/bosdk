#ifndef BOSDK_BODAL_CORE_ADC_H_
#define BOSDK_BODAL_CORE_ADC_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_ADC)

#define BODAL_ADC_MAX_CHANNEL            HW_ADC_MAX_CHANNEL

bool adcInit(void);

uint16_t adcRead(uint8_t channel);
uint16_t adcRead8(uint8_t channel);
uint16_t adcRead10(uint8_t channel);
uint16_t adcRead12(uint8_t channel);
uint16_t adcRead16(uint8_t channel);
uint16_t adcReadVoltage(uint8_t channel);
uint16_t adcConvVoltage(uint8_t channel, uint32_t adc_value);

uint8_t  adcGetRes(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_ADC */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_ADC_H_ */
