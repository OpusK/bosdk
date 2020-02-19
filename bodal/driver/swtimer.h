#ifndef BOSDK_BODAL_DRIVER_SWTIMER_H_
#define BOSDK_BODAL_DRIVER_SWTIMER_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include <bosdk_config.h>

#if(BOSDK_ENABLE_BODAL_DRIVER_SWTIMER)

#include <stdint.h>
#include <stdbool.h>

#ifndef ON
#define ON 1
#endif

#ifndef OFF
#define OFF 0
#endif

#ifndef NULL
#define NULL 0
#endif

#define BODAL_SWTIMER_MAX_CH        HW_SWTIMER_MAX_CH

#define ONE_TIME            1
#define LOOP_TIME           2

typedef int16_t             swtimer_handle_t;

bool swtimerInit(void);
void swtimerSet  (uint8_t TmrNum, uint32_t TmrData, uint8_t TmrMode, void (*Fnct)(void *),void *arg);
void swtimerStart(uint8_t TmrNum);
void swtimerStop (uint8_t TmrNum);
void swtimerReset(uint8_t TmrNum);
void swtimerISR(void);

int16_t  swtimerGetHandle(void);
uint32_t swtimerGetCounter(void);

#endif /* BOSDK_ENABLE_BODAL_DRIVER_SWTIMER */

#ifdef __cplusplus
}
#endif


#endif /* BOSDK_BODAL_DRIVER_SWTIMER_H_ */
