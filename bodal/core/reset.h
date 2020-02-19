#ifndef BOSDK_BODAL_CORE_RESET_H_
#define BOSDK_BODAL_CORE_RESET_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_RESET)

#include <stdbool.h>
#include <stdint.h>

bool resetInit(void);
uint8_t resetGetStatus(void);
void resetRunWdgReset(void);
void resetRunSoftReset(void);
void resetClearFlag(void);

#endif /* BOSDK_ENABLE_BODAL_CORE_RESET */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_RESET_H_ */
