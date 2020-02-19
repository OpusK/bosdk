#ifndef BOSDK_BODAL_CORE_FLASH_H_
#define BOSDK_BODAL_CORE_FLASH_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_FLASH)

bool flashInit(void);

err_code_t flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
err_code_t flashRead(uint32_t addr, uint8_t *p_data, uint32_t length);
err_code_t flashErase(uint32_t addr, uint32_t length);

#endif /* BOSDK_ENABLE_BODAL_CORE_FLASH */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_FLASH_H_ */
