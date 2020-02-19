#ifndef BOSDK_BODAL_CORE_VCP_H_
#define BOSDK_BODAL_CORE_VCP_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_VCP)

#include <stdbool.h>
#include <stdint.h>

bool     vcpInit(void);
bool     vcpFlush(void);
uint32_t vcpAvailable(void);
void     vcpPutch(uint8_t ch);
uint8_t  vcpGetch(void);
int32_t  vcpWrite(uint8_t *p_data, uint32_t length);
int32_t  vcpWriteTimeout(uint8_t *p_data, uint32_t length, uint32_t timeout);
uint8_t  vcpRead(void);
uint32_t vcpGetTxErrCount(void);
uint32_t vcpGetTxCount(void);
uint32_t vcpGetTxRetryCount(void);
bool     vcpIsConnected(void);
uint32_t vcpGetBaud(void);
void vcpClearBaud(void);

int32_t  vcpPrintf( const char *fmt, ...);

#endif /* BOSDK_ENABLE_BODAL_CORE_VCP */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_VCP_H_ */
