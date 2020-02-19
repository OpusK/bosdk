#ifndef BOSDK_BODAL_DRIVER_ENCODER_H_
#define BOSDK_BODAL_DRIVER_ENCODER_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_ENCODER)

#include <stdint.h>
#include <stdbool.h>

bool     encoderInit(void);

uint16_t encoderReadValue(uint8_t ch);
uint32_t encoderReadCount(uint8_t ch);
uint32_t encoderReadSpeed(uint8_t ch);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_ENCODER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_ENCODER_H_ */
