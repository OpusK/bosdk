#ifndef BOSDK_BODAL_CORE_I2C_H_
#define BOSDK_BODAL_CORE_I2C_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_I2C)

#define i2cRead  i2cReadBytes
#define i2cWrite i2cWriteBytes

#define BODAL_I2C_MAX_CH      HW_I2C_MAX_CH

bool i2cInit(void);
bool i2cBegin(uint8_t ch, uint32_t freq_khz);
bool i2cReadByte (uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t timeout);
bool i2cReadBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

bool i2cWriteByte (uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t data, uint32_t timeout);
bool i2cWriteBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

void     i2cSetTimeout(uint8_t ch, uint32_t timeout);
uint32_t i2cGetTimeout(uint8_t ch);

void     i2cClearErrCount(uint8_t ch);
uint32_t i2cGetErrCount(uint8_t ch);

#endif /* BOSDK_ENABLE_BODAL_CORE_I2C */

#ifdef __cplusplus
 }
#endif


#endif /* BOSDK_BODAL_CORE_I2C_H_ */
