#ifndef BOSDK_BODAL_CORE_SPI_H_
#define BOSDK_BODAL_CORE_SPI_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_SPI)

#define BODAL_SPI_MAX_CH            HW_SPI_MAX_CH

bool      spiInit(void);

void      spiBegin(uint8_t ch);
void      spiSetBitOrder(uint8_t ch, uint8_t bitOrder);
void      spiSetClockDivider(uint8_t ch, uint8_t clockDiv);
void      spiSetDataMode(uint8_t ch, uint8_t dataMode);

bool      spiWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
bool      spiWrite8(uint8_t ch, uint8_t data);
bool      spiWrite16(uint8_t ch, uint16_t data);

bool      spiRead(uint8_t ch, uint8_t *p_data, uint32_t length);
bool      spiRead8(uint8_t ch, uint8_t *p_data);
bool      spiRead16(uint8_t ch, uint16_t *p_data);

bool      spiTransfer(uint8_t ch, uint8_t *p_tx_data, uint8_t *p_rx_data, uint32_t length);
uint8_t   spiTransfer8(uint8_t ch, uint8_t data);
uint16_t  spiTransfer16(uint8_t ch, uint16_t data);

void      spiSetTimeout(uint8_t ch, uint32_t timeout);
uint32_t  spiGetTimeout(uint8_t ch);

void      spiSetCS(uint8_t ch, uint8_t state);

#endif /* BOSDK_ENABLE_BODAL_CORE_SPI */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_CORE_SPI_H_ */
