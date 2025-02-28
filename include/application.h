

#ifndef APPLICATION_H
#define APPLICATION_H

#include <hal/constants/all.h>

// Also see the following files generated by SMT32CubeMX : 
//   include/stm32u0xx_hal_conf.h

#define APP_UCDM_MAX_REGISTERS              255
#define APP_ENABLE_LIBVERSION_DESCRIPTORS   1

/**
 * @name Application Descriptors Configuration
 * 
 * Various descriptrs used to identify the application. For USB enumeration, 
 * the following descriptors must be minimally specified : 
 * 
 *  - APP_DESCRIPTOR_VENDOR_NAME : USB Device Manufacturer
 *  - APP_DESCRIPTOR_HARDWARE_NAME : USB Product Name
 * 
 */
/**@{*/
#define APP_DESCRIPTOR_VENDOR_NAME          "EBS Development"
#define APP_DESCRIPTOR_VENDOR_URL           "https://github.com/ebs-universe"

#define APP_DESCRIPTOR_HARDWARE_NAME        "Nucleo STM32H7S3L8"
#define APP_DESCRIPTOR_HARDWARE_REVISION    "B02"
#define APP_DESCRIPTOR_HARDWARE_VARIANT     ""    

#define APP_DESCRIPTOR_FIRMWARE_NAME        "EBS Platform Development Stack"
#define APP_DESCRIPTOR_FIRMWARE_REVISION    "9.9.9"
/**@}*/

/**
 * @name Application CPU Features Configuration
 * 
 * See : 
 *   - core_init() of core_impl.c, and specifically, 
 *   - cpu_init() of core_impl.c
 *   - mpu_init() of core_impl.c
 * 
 * This is also related to the use of DTCM and ITCM.
 */
/**@{*/   
#define  APP_ENABLE_INSTRUCTION_CACHE       0U
#define  APP_ENABLE_DATA_CACHE              0U
#define  APP_ENABLE_SPECULATIVE_EXECUTION   0U
/**@}*/ 

/**
 * @name Application XSPI Configuration
 * 
 * These are not actually supported by the implementation at
 * this time, and the defines are only used to control power 
 * to the interfaces. Expect these interfaces to change when  
 * external memory support is added.
 * 
 */
/**@{*/   
    #define APP_ENABLE_XSPIM1          0
    #define APP_ENABLE_XSPIM2          1
/**@}*/ 


/**
 * @name Application GPIO Configuration
 */
/**@{*/   
    #define APP_ENABLE_GPIO            1
/**@}*/ 

/**
 * @name Application Systick and Time Configuration
 */
/**@{*/   
    #define APP_ENABLE_SYSTICK         1
    #define APP_USE_CORE_SYSTICK       1
    #define APP_ENABLE_TIME_CRON       1
    #define APP_ENABLE_TIME_SYNC       1
    #define APP_ENABLE_RTC             0
    #define APP_ENABLE_RTC_1HZ_OUT     0
/**@}*/ 

/**
 * @name Application Device ID Configuration
 */
/**@{*/   
    #define APP_ENABLE_ID               1
    #define APP_ID_TRIMFUNC             1
/**@}*/ 

/**
 * @name Application EEPROM Configuration
 */
/**@{*/
    #define APP_ENABLE_EEPROM           0
    #define APP_EEPROM_PROVIDER         2
    #define APP_EEPROM_SIZE             1024
    #define APP_EEPROM_SIZETYPE         uint16_t
/**@}*/ 

/**
 * @name Application Entropy Configuration
 */
/**@{*/   
    #define APP_ENABLE_RAND             0
    #define APP_ENABLE_ENTROPY          APP_ENABLE_RAND
    #define APP_ENTROPY_POOL_SIZE       16
    #define APP_ENTROPY_MODE            2
/**@}*/ 

/**
 * @name Application Timers Configuration
 */
/**@{*/   
    #define APP_ENABLE_TIMER            1
    
    // GP 16b 2CC DMA
    #define APP_ENABLE_TIM15            1   

    #define uC_TIM15_CYCLE_FREQ         1500000
    #define uC_TIM15_CH1_OUTPUT_MODE    TIMER_OUTMODE_TOGGLE
    #define uC_TIM15_TRIGGEN_SRC        TIMER_TRIGGEN_TOP
/**@}*/ 

/**
 * @name Application Low Power Timers Configuration
 *      
 * Not implemented
 */
/**@{*/     
/**@}*/ 


/**
 * @name Application ADC Configuration
 */
/**@{*/   
    #define APP_ENABLE_ADC              1           
    #define APP_ADC1_MODE               ADC_MODE_SCAN
    #define APP_ADC2_MODE               ADC_MODE_DISABLED

    #define APP_ADC_CONFIGURE_CHANNELS  EBS_TRUE
    #define APP_ADC_DM_MODE             ADC_DM_DMA
    #define APP_ADC_DMA_BUFFER_LENGTH   256
    #define APP_ADC_DMA_CHANNEL         uC_DMA1_CH13_INTFNUM
    
    #define uC_ADC_CLOCK_PRESCALER      ADC_CCR_PRESC_2
    // #define uC_ADC_TIMING_MONITOR_GPIO  GPIO_DBG_SCOPE1
    #define uC_ADC1_TRIGSRC             0x4E  // tim15_trgo // adc_ext_trg14 // both edges
    
    // 0: disable, 1: ADC1, 2: ADC2
    #define APP_ENABLE_AIN0             0   // Fast
    #define APP_ENABLE_AIN1             0   // Fast
    #define APP_ENABLE_AIN2             1   // Fast // Nucleo
    #define APP_ENABLE_AIN3             0   // Fast
    #define APP_ENABLE_AIN4             0   // 1   // Fast // Nucleo
    #define APP_ENABLE_AIN5             0   // 1   // Fast // Nucleo
    #define APP_ENABLE_AIN6             0   // 1   // Slow // Nucleo
    #define APP_ENABLE_AIN7             0   // Slow
    #define APP_ENABLE_AIN8             0   // 1   // Slow // Nucleo
    #define APP_ENABLE_AIN9             0   // Slow
    #define APP_ENABLE_AIN10            0   // 1 // Slow // Nucleo
    #define APP_ENABLE_AIN11            0   // Slow
    #define APP_ENABLE_AIN12            0   // 1   // Slow // Nucleo
    #define APP_ENABLE_AIN13            0   // 1   // Slow // Nucleo
    #define APP_ENABLE_AIN14            0   // Slow
    #define APP_ENABLE_AIN15            0   // 1   // Slow // Nucleo
    #define APP_ENABLE_AIN18            0   // Slow
    #define APP_ENABLE_AIN_TEMP         0   // 1   // Slow // ADC1 Only
    #define APP_ENABLE_AIN_IREF         0   // Slow // ADC1 Only
    #define APP_ENABLE_AIN_VBAT         0   // Slow // ADC2 Only
    #define APP_ENABLE_AIN_VDDC         0   // Slow // ADC2 Only

    #define uC_ADC1_CHANNEL_COUNT       1
    #define uC_ADC2_CHANNEL_COUNT       0
/**@}*/ 

/**
 * @name Application UART Configuration
 */
/**@{*/
    #define APP_ENABLE_UART             1

    #define APP_ENABLE_UART1            0  // A
    #define APP_ENABLE_UART2            0  // B
    #define APP_ENABLE_UART3            1  // Backchannel
    #define APP_ENABLE_UART6            0  // lp

    #define uC_UART3_BAUD               1000000 
/**@}*/ 

/**
 * @name Application Crypto Configuration
 * 
 * Common Parameters 
 *   - APP_ENABLE_CRYPTO 
 *   - APP_CRYPTO_HARDWARE 
 *   - APP_CRYPTO_INTERRUPT
 * 
 * No Default Context  
 *   - APP_CRYPTO_NO_DEFAULT_CONTEXT
 * 
 * Default Context
 *   - APP_CRYPTO_ALG
 *   - APP_CRYPTO_KEYSIZE
 *   - APP_CRYPTO_IVSIZE
 *   - APP_CRYPTO_KEY
 *   - APP_CRYPTO_IV  
 */
/**@{*/   
    #define APP_ENABLE_CRYPTO           0
    #define APP_CRYPTO_HARDWARE         CRYPTO_HW_ALWAYS
    #define APP_CRYPTO_INTERRUPT        1
    #define APP_CRYPTO_ALG              CRYPTO_AES_GCM
    #define APP_CRYPTO_KEYSIZE          128
    #define APP_CRYPTO_IVSIZE           96
    #define APP_CRYPTO_INGESTSIZE       128
    #define APP_CRYPTO_BLOCKSIZE        0
    #define APP_CRYPTO_HEADERSIZE       0
    #define APP_CRYPTO_MACSIZE          128
    #define APP_CRYPTO_KEY              {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F} 
    #define APP_CRYPTO_IV               ((DLMS_SYSTEM_TITLE << 32) | DLMS_INVOCATION_COUNTER)
    #define APP_CRYPTO_SWAP             CRYPTO_SWAP_NONE
    #define APP_CRYPTO_MODE             CRYPTO_CTX_MODE_ENCRYPTION
/**@}*/

/**
 * @name Application USB Configuration 
 */
/**@{*/
    #define APP_ENABLE_USB_HOST         0   // Not implemented
    #define APP_ENABLE_USB_DEVICE       0  
    #define APP_ENABLE_USB              (APP_ENABLE_USB_DEVICE | APP_ENABLE_USB_HOST)
    #define APP_USB_DEVICE_RHPORT       1
    #define APP_USB_POWER               400
    #define APP_USB_DESCR_VID           1155
    #define APP_USB_DESCR_PID           22336
    #define APP_USB_DESCR_VERSION       0x0100
    #define APP_BLINK_FOR_USB_STATUS    1

    #define APP_ENABLE_USBCDC0          1
    #define APP_ENABLE_USBCDC1          1
    #define APP_ENABLE_USBCDC2          1

    // tusb needs this total, and we want it to only use application.h to fill
    // out its config
    #define APP_USBCDC_IFACES           (APP_ENABLE_USBCDC0 + APP_ENABLE_USBCDC1 + APP_ENABLE_USBCDC2)
    
    #define APP_ENABLE_USBCDC0_PT       0
    #define APP_ENABLE_USBCDC1_PT       0
    #define APP_ENABLE_USBCDC2_PT       0

    #if APP_USBCDC_IFACES >= 3
    #define APP_USB_DESCR_IF_CDC0       "Control Interface"
    #define APP_USB_DESCR_IF_CDC1       "Bulk Interface"
    #define APP_USB_DESCR_IF_CDC2       "Backchannel Interface"
    #elif APP_USBCDC_IFACES == 2
    #define APP_USB_DESCR_IF_CDC0       "Primary Interface"
    #define APP_USB_DESCR_IF_CDC1       "Backchannel Interface"
    #else 
    #define APP_USB_DESCR_IF_CDC0       "Primary Interface"
    #endif
/**@}*/ 

/**
 * @name Application Primary Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_PRIF             1
    #define APP_PRIF_TYPE               EBS_INTF_UART
    #define APP_PRIF_INTFNUM            0
/**@}*/ 

/**
 * @name Application Bulk Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_BULKIF           0
    #define APP_BULKIF_TYPE             EBS_INTF_UART
    #define APP_BULKIF_INTFNUM          0
/**@}*/ 

/**
 * @name Application Backchannel Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_BCIF             0
    #define APP_BCIF_TYPE               EBS_INTF_UART
    #define APP_BCIF_INTFNUM            0
/**@}*/ 

/** 
 * @name Application DMA Configuration
 */
/**@{*/   
    #define APP_ENABLE_DMA              1

    #define APP_ENABLE_DMA1_CH12        1   // HPDMA for memcpy
    #define APP_ENABLE_DMA1_CH13        1   // HPDMA for ADC1
    
    #define APP_ENABLE_DMA2_CH12        1   // GPDMA for memcpy
    
    #define uC_DMA1_CH13_TYPE           DMA_CHN_TYPE_CIRCULAR
    #define uC_DMA1_CH13_PRIORITY       DMA_PRIORITY_IMMEDIATE
/**@}*/ 

/**
 * @name Application Common Infrastructure Configuration
 */
/**@{*/   
    #define APP_ENABLE_OUTPUT_BLINK     1
    #define BLINK_GPIO                  GPIO_LED_YELLOW
    #define BLINK_POLARITY              1

    #define APP_ENABLE_OUTPUT_ERROR     1
    #define ERROR_GPIO                  GPIO_LED_RED
    #define ERROR_POLARITY              1

    // button appears to be broken. unclear if it is a 
    // hardware or software issue.  
    #define APP_ENABLE_BUTTON           0
/**@}*/

/**
 * @name Application Debug Configuration
 */
/**@{*/   
    #define APP_ENABLE_DEBUG                 1

    #if APP_ENABLE_BCIF
        #define DEBUG_TRANSPORT_INTFNUM      APP_BCIF_INTFNUM
        #define DEBUG_TRANSPORT_TYPE         APP_BCIF_TYPE
    #elif APP_ENABLE_PRIF
        #define DEBUG_TRANSPORT_INTFNUM      APP_PRIF_INTFNUM
        #define DEBUG_TRANSPORT_TYPE         APP_PRIF_TYPE      
    #endif
/**@}*/

/**
 * @name Application Modbus Configuration
 */
/**@{*/   
    #define APP_ENABLE_MODBUS           0
    
    #if APP_ENABLE_PRIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_PRIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_PRIF_TYPE
    #elif APP_ENABLE_BCIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_BCIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_BCIF_TYPE
    #endif

    #define MODBUS_PLUGGABLE_TRANSPORTS      0
    #define MODBUS_DEFAULT_DEVICE_ADDRESS    0x05
/**@}*/

/**
 * @name Application Testing Configuration
 */
/**@{*/   
    #ifndef TEST_SERIAL_INTFNUM
        #if APP_ENABLE_PRIF
            #define TEST_SERIAL_INTFNUM   APP_PRIF_INTFNUM
            #define TEST_SERIAL_TYPE      APP_PRIF_TYPE
        #elif APP_ENABLE_BCIF
            #define TEST_SERIAL_INTFNUM   APP_BCIF_INTFNUM
            #define TEST_SERIAL_TYPE      APP_BCIF_TYPE
        #endif
    #endif
    #ifndef TEST_SERIAL_TYPE
        #define TEST_SERIAL_TYPE          EBS_INTF_UART
    #endif
/**@}*/ 

/**
 * @name Application DMA Demonstration Configuration
 */
/**@{*/ 
    #define APP_DMADEMO_MEMCPY_CHANNEL       uC_DMA2_CH12_INTFNUM
    #define APP_DMADEMO_MEMCPY_DTCM_CHANNEL  uC_DMA1_CH12_INTFNUM
/**@}*/ 

#endif