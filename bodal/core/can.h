#ifndef BOSDK_BODAL_CORE_CAN_H_
#define BOSDK_BODAL_CORE_CAN_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_CORE_CAN)

#define BODAL_CAN_MAX_CHANNEL       HW_CAN_MAX_CHANNEL
#define BODAL_CAN_MSG_RX_BUF_MAX    HW_CAN_MSG_RX_BUF_MAX
#define BODAL_CAN_DATA_RX_BUF_MAX   HW_CAN_DATA_RX_BUF_MAX

typedef struct {
  uint32_t id;
  uint32_t length;
  uint8_t  data[8];
  uint8_t  format;
} can_msg_t;

bool canInit(void);
bool canOpen(uint8_t channel, uint32_t baudrate, uint8_t format);
void canClose(uint8_t channel);
bool canConfigFilter(uint8_t filter_num, uint32_t id, uint32_t mask, uint8_t format);

uint32_t canWrite(uint8_t channel, uint32_t id, uint8_t *p_data, uint32_t length);
uint8_t  canRead(uint8_t channel);
uint32_t canAvailable(uint8_t channel);
uint32_t canWriteMsg(uint8_t channel, can_msg_t *p_msg);
bool     canReadMsg(uint8_t channel, can_msg_t *p_msg);
uint32_t canAvailableMsg(uint8_t channel);

uint8_t  canGetErrCount(uint8_t channel);
uint32_t canGetError(uint8_t channel);
uint32_t canGetState(uint8_t channel);

void canAttachRxInterrupt(uint8_t channel, void (*handler)(can_msg_t *arg));
void canDetachRxInterrupt(uint8_t channel);

#endif /* BOSDK_ENABLE_BODAL_CORE_CAN */

#ifdef __cplusplus
 }
#endif


#endif /* BOSDK_BODAL_CORE_CAN_H_ */
