#ifndef _BOARD_GPIO_H_
#define _BOARD_GPIO_H_

/*********************************************************************
 * INCLUDES
 */
#include "driver/gpio.h"

/*********************************************************************
 * DEFINITIONS
 */
#define NFC_RST_GPIO_PIN                GPIO_NUM_25         // NFC复位
#define NFC_RST_LOW                     0x00
#define NFC_RST_HIGH                    0x01

/*********************************************************************
 * API FUNCTIONS
 */
void NFC_GPIO_Init(void);
void NFC_GPIO_Write(uint8_t mode);

#endif /* _BOARD_GPIO_H_ */