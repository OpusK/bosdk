#ifndef BOSDK_BODAL_DRIVER_DXLPORT_H_
#define BOSDK_BODAL_DRIVER_DXLPORT_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_DXLPORT)

#define BODAL_DXLPORT_MAX_CH    HW_DXLPORT_MAX_CH

bool dxlportInit(void);

bool dxlportOpen(uint8_t ch, uint32_t baud);
bool dxlportClose(uint8_t ch);
bool dxlportFlush(uint8_t ch);
void dxlportTxEnable(uint8_t ch);
void dxlportTxDisable(uint8_t ch);
void dxlportPowerEnable(uint8_t ch);
void dxlportPowerDisable(uint8_t ch);
bool dxlportGetPower(uint8_t ch);
void dxlportSetTxDoneISR(uint8_t ch, void (*p_txDoneISR)(void));
bool dxlportIsTxDone(uint8_t ch);

uint32_t dxlportAvailable(uint8_t ch);
uint8_t  dxlportRead(uint8_t ch);
uint32_t dxlportWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t dxlportWritePoll(uint8_t ch, uint8_t *p_data, uint32_t length, uint32_t timeout);
int32_t  dxlportPrintf(uint8_t ch, const char *fmt, ...);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_DXLPORT */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_DXLPORT_H_ */
