#ifndef BOSDK_BODAL_DRIVER_EEPROM_H_
#define BOSDK_BODAL_DRIVER_EEPROM_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_EEPROM)

#include <stdint.h>
#include <stdbool.h>

bool eepromInit();

uint8_t  eepromReadByte(uint32_t addr);
bool     eepromWriteByte(uint32_t index, uint8_t data_in);
uint32_t eepromGetLength(void);
bool     eepromFormat(void);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_EEPROM */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_EEPROM_H_ */

