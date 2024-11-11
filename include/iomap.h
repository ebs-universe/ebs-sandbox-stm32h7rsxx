#ifndef __IOMAP_H
#define __IOMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7rsxx_hal.h"
#include "clocktree.h"

/**
 * @name Application Specific GPIOs
 */
/**@{*/ 


/**@}*/ 

/**
 * @name GPIOs for User Buttons
 */
/**@{*/ 
#define K0_PIN              13  
#define K0_PORT             GPIOC_BASE
#define GPIO_K0             K0_PORT, K0_PIN  
/**@}*/ 

/**
 * @name GPIOs for User LEDs
 */
/**@{*/ 
#define LED1_PIN            10   
#define LED1_PORT           GPIOD_BASE
#define GPIO_LED1           LED1_PORT, LED1_PIN 
#define GPIO_LED_GREEN      GPIO_LED1

#define LED2_PIN            13   
#define LED2_PORT           GPIOD_BASE
#define GPIO_LED2           LED2_PORT, LED2_PIN 
#define GPIO_LED_YELLOW     GPIO_LED2

#define LED3_PIN            7   
#define LED3_PORT           GPIOB_BASE
#define GPIO_LED3           LED3_PORT, LED3_PIN 
#define GPIO_LED_RED        GPIO_LED3
/**@}*/ 

/**
 * @name GPIOs associated with UART Interfaces
 * 
 * - BC : USART3, connected to the VCP of the stlink on the nucleo
 * - 1  : USART1, available on nucleo arduino shield as USART_A
 * - 2  : USART2, available on nucleo arduino shield as USART_B
 * 
 * USARTB has some kind of conflict with ETH_CLK. This should be 
 * investigated. USARTB also supports sync USART and hardware flow 
 * control.
 */
/**@{*/ 
#define USART3_TX_PIN       8
#define USART3_TX_PORT      GPIOD_BASE
#define GPIO_USART3_TX      USART3_TX_PORT, USART3_TX_PIN
#define GPIO_BCTX           GPIO_USART3_TX

#define USART3_RX_PIN       9
#define USART3_RX_PORT      GPIOD_BASE
#define GPIO_USART3_RX      USART3_RX_PORT, USART3_RX_PIN
#define GPIO_BCRX           GPIO_USART3_RX

#define USART1_TX_PIN       14
#define USART1_TX_PORT      GPIOB_BASE
#define GPIO_USART1_TX      USART1_TX_PORT, USART1_TX_PIN
#define GPIO_SHLD_UARTA_TX  GPIO_USART1_TX

#define USART1_RX_PIN       10
#define USART1_RX_PORT      GPIOA_BASE
#define GPIO_USART1_RX      USART1_RX_PORT, USART1_RX_PIN
#define GPIO_SHLD_UARTA_RX  GPIO_USART1_RX
/**@}*/ 

/**
 * @name GPIOs associated with SPI Interfaces
 * 
 * - 1  : SPI1, available on nucleo arduino shield as SPI_A
 * - 3  : SPI3, available on nucleo arduino shield as SPI_B
 * 
 * SPI3 also has its NSS pin exposed, so can be used as an SPI 
 * slave interface. 
 * 
 */
/**@{*/ 
#define SPI1_MOSI_PIN       5
#define SPI1_MOSI_PORT      GPIOB_BASE
#define GPIO_SPI1_MOSI      SPI1_MOSI_PORT, SPI1_MOSI_PIN

#define SPI1_MISO_PIN       6
#define SPI1_MISO_PORT      GPIOA_BASE
#define GPIO_SPI1_MISO      SPI1_MISO_PORT, SPI1_MISO_PIN

#define SPI1_SCLK_PIN       5
#define SPI1_SCLK_PORT      GPIOA_BASE
#define GPIO_SPI1_SCLK      SPI1_SCLK_PORT, SPI1_SCLK_PIN

#define SPI3_MOSI_PIN       2
#define SPI3_MOSI_PORT      GPIOB_BASE
#define GPIO_SPI3_MOSI      SPI3_MOSI_PORT, SPI3_MOSI_PIN

#define SPI3_MISO_PIN       4
#define SPI3_MISO_PORT      GPIOB_BASE
#define GPIO_SPI3_MISO      SPI3_MISO_PORT, SPI3_MISO_PIN

#define SPI3_SCLK_PIN       3
#define SPI3_SCLK_PORT      GPIOB_BASE
#define GPIO_SPI3_SCLK      SPI3_SCLK_PORT, SPI3_SCLK_PIN

#define SPI3_NSS_PIN        4
#define SPI3_NSS_PORT       GPIOA_BASE
#define GPIO_SPI3_NSS       SPI3_NSS_PORT, SPI3_NSS_PIN
/**@}*/ 

/**
 * @name GPIOs associated with I2C Interfaces
 * 
 * - I2C_SYS : I2C3, connected to the USB power control IC on the nucleo
 * - I2C1  : I2C1, available on nucleo arduino shield as I2C_A
 * - I2C2  : I2C2 with SMBUS Alert, available on nucleo arduino shield as I2C_B
 * 
 */
/**@{*/ 
#define I2C3_SCL_PIN        8
#define I2C3_SCL_PORT       GPIOA_BASE
#define GPIO_I2C3_SCL       I2C3_SCL_PORT, I2C3_SCL_PIN
#define GPIO_I2C_SYS_SCL    GPIO_I2C3_SCL

#define I2C3_SDA_PIN        9
#define I2C3_SDA_PORT       GPIOA_BASE
#define GPIO_I2C3_SDA       I2C3_SDA_PORT, I2C3_SDA_PIN
#define GPIO_I2C_SYS_SDA    GPIO_I2C3_SDA

#define I2C1_SCL_PIN        8
#define I2C1_SCL_PORT       GPIOB_BASE
#define GPIO_I2C1_SCL       I2C1_SCL_PORT, I2C1_SCL_PIN

#define I2C1_SDA_PIN        9
#define I2C1_SDA_PORT       GPIOB_BASE
#define GPIO_I2C1_SDA       I2C1_SDA_PORT, I2C1_SDA_PIN

#define I2C2_SCL_PIN        1
#define I2C2_SCL_PORT       GPIOF_BASE
#define GPIO_I2C2_SCL       I2C1_SCL_PORT, I2C1_SCL_PIN

#define I2C2_SDA_PIN        0
#define I2C2_SDA_PORT       GPIOF_BASE
#define GPIO_I2C2_SDA       I2C2_SDA_PORT, I2C2_SDA_PIN

#define I2C2_SMBA_PIN       2
#define I2C2_SMBA_PORT      GPIOF_BASE
#define GPIO_I2C2_SMBA      I2C2_SMBA_PORT, I2C1_SMBA_PIN
/**@}*/ 

/**
 * @name GPIOs associated with CAN Interfaces
 * 
 * FDCAN1 available on Nucleo Arduino header.
 */
/**@{*/ 
#define FDCAN1_TX_PIN       1
#define FDCAN1_TX_PORT      GPIOD_BASE
#define GPIO_FDCAN1_TX      FDCAN1_TX_PORT, FDCAN1_TX_PIN

#define FDCAN1_RX_PIN       0
#define FDCAN1_RX_PORT      GPIOD_BASE
#define GPIO_FDCAN1_RX      FDCAN1_RX_PORT, FDCAN1_RX_PIN
/**@}*/

/**
 * @name GPIOs associated with ADC inputs
 * 
 * These are the ADC inputs exposed on the Nucleo's Arduino compatible
 * connector. 
 * 
 */
/**@{*/ 
#define AIN2_PIN            11   
#define AIN2_PORT           GPIOF_BASE
#define GPIO_AIN2           AIN2_PORT, AIN2_PIN 
#define GPIO_SHLD_A5        GPIO_AIN2
#define ADC_CHN_SHLD_A5     2

#define AIN4_PIN            4   
#define AIN4_PORT           GPIOC_BASE
#define GPIO_AIN4           AIN4_PORT, AIN4_PIN 
#define GPIO_SHLD_A3        GPIO_AIN4
#define ADC_CHN_SHLD_A3     4

#define AIN5_PIN            1   
#define AIN5_PORT           GPIOB_BASE
#define GPIO_AIN5           AIN5_PORT, AIN5_PIN 
#define GPIO_SHLD_A6        GPIO_AIN5
#define ADC_CHN_SHLD_A6     5

#define AIN6_PIN            12   
#define AIN6_PORT           GPIOF_BASE
#define GPIO_AIN6           AIN6_PORT, AIN6_PIN 
#define GPIO_SHLD_A8        GPIO_AIN6
#define ADC_CHN_SHLD_A8     6

#define AIN8_PIN            5   
#define AIN8_PORT           GPIOC_BASE
#define GPIO_AIN8           AIN8_PORT, AIN8_PIN 
#define GPIO_SHLD_A4        GPIO_AIN8
#define ADC_CHN_SHLD_A4     8

#define AIN10_PIN           0   
#define AIN10_PORT          GPIOC_BASE
#define GPIO_AIN10          AIN10_PORT, AIN10_PIN 
#define GPIO_SHLD_A1        GPIO_AIN10
#define ADC_CHN_SHLD_A1     10

#define AIN12_PIN           2   
#define AIN12_PORT          GPIOC_BASE
#define GPIO_AIN12          AIN12_PORT, AIN12_PIN 
#define GPIO_SHLD_A7        GPIO_AIN12
#define ADC_CHN_SHLD_A7     12

#define AIN13_PIN           3 
#define AIN13_PORT          GPIOC_BASE
#define GPIO_AIN13          AIN13_PORT, AIN13_PIN 
#define GPIO_SHLD_A2        GPIO_AIN13
#define ADC_CHN_SHLD_A2     13

#define AIN15_PIN           3 
#define AIN15_PORT          GPIOA_BASE
#define GPIO_AIN15          AIN15_PORT, AIN15_PIN 
#define GPIO_SHLD_A0        GPIO_AIN15
#define ADC_CHN_SHLD_A0     15
/**@}*/ 

/**
 * @name GPIOs Associated with the USB and UCPD peripherals
 * 
 * Nucleo exposes USB HS with the UCPD on a Type C PD capable 
 * interface. The USB_INT and USB_PWREN pins are associated with the 
 * Type C PD IC included in the Nucleo. Use case is unknown. These 
 * pins as well as CC1/2 pins are likely not necessary for the usual 
 * USB 2.0 (non Type C PD) interface. 
 * 
 */
/**@{*/ 
#define USBHS_DP_PIN        6   
#define USBHS_DP_PORT       GPIOM_BASE
#define GPIO_USBHS_DP       USBHS_DP_PORT, USBHS_DP_PIN
#define USBHS_DP_AF         

#define USBHS_DM_PIN        5   
#define USBHS_DM_PORT       GPIOM_BASE
#define GPIO_USBHS_DM       USBHS_DM_PORT, USBHS_DM_PIN
#define USBHS_DM_AF         

#define USBFS_DP_PIN        11   
#define USBFS_DP_PORT       GPIOM_BASE
#define GPIO_USBFS_DP       USBFS_DP_PORT, USBFS_DP_PIN
#define USBFS_DP_AF         USB

#define USBFS_DM_PIN        12   
#define USBFS_DM_PORT       GPIOM_BASE
#define GPIO_USBFS_DM       USBFS_DM_PORT, USBFS_DM_PIN
#define USBFS_DM_AF         

#define UCPD_CC1_PIN        0   
#define UCPD_CC1_PORT       GPIOM_BASE
#define GPIO_UCPD_CC1       UCPD_CC1_PORT, UCPD_CC1_PIN

#define UCPD_CC2_PIN        0   
#define UCPD_CC2_PORT       GPIOM_BASE
#define GPIO_UCPD_CC2       UCPD_CC2_PORT, UCPD_CC2_PIN

#define USB_INT_PIN         8   
#define USB_INT_PORT        GPIOM_BASE
#define GPIO_USB_INT        USB_INT_PORT, USB_INT_PIN

#define USB_PWREN_PIN       9   
#define USB_PWREN_PORT      GPIOM_BASE
#define GPIO_USB_PWREN      USB_PWREN_PORT, USB_PWREN_PIN
/**@}*/ 

/**
 * @name GPIOs associated with the SWD Debug Interface
 * 
 * This is connected to the on-board stlink of the 
 * nucleo board
 * 
 */
/**@{*/ 
#define SWDIO_PIN           13
#define SWDIO_PORT          GPIOA_BASE
#define GPIO_SWDIO          SWDIO_PORT, SWDIO_PIN

#define SWCLK_PIN           14
#define SWCLK_PORT          GPIOA_BASE
#define GPIO_SWCLK          SWCLK_PORT, SWCLK_PIN
/**@}*/ 


/**
 * @name GPIOs associated with crystal oscillators
 * 
 * The nucleo does not have a high speed crystal installed. 
 */
/**@{*/ 
#define OSC32IN_PIN         14   
#define OSC32IN_PORT        GPIOC_BASE
#define GPIO_OSC32IN        OSC32IN_PORT, OSC32IN_PIN 

#define OSC32OUT_PIN        15   
#define OSC32OUT_PORT       GPIOC_BASE
#define GPIO_OSC32OUT       OSC32OUT_PORT, OSC32OUT_PIN 

#define OSCIN_PIN           0   
#define OSCIN_PORT          GPIOH_BASE
#define GPIO_OSCIN          OSCIN_PORT, OSCIN_PIN 

#define OSCOUT_PIN          1   
#define OSCOUT_PORT         GPIOH_BASE
#define GPIO_OSCOUT         OSCOUT_PORT, OSCOUT_PIN 
/**@}*/ 

#ifdef __cplusplus
}
#endif

#endif
