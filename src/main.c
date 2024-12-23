

#include <string.h>
#include <application.h>
#include <irq_handlers.h>
#include <iomap.h>
#include <hal/uc.h>

#include "bsp/gpio.h"
#include "bsp/usb.h"

#include <ucdm/ucdm.h>
#include "ebs/time_if.h"
#include <time/time.h>
#include <time/cron.h>
#include <modbus/modbus.h>

#include <blink.h>
#include <tasks/uart_bare.h>
#include <tasks/usb_task.h>

#include <demos/itcm_demo.h>
#include <demos/adc_demo.h>
#include <demos/dma_demo.h>

ucdm_addr_t next_address;

static void setup_handlers(void) {
    __core_handler_inclusion = 1;
    __shared_handler_inclusion = 1;
    __exti_handler_inclusion = 1;
    __entropy_handler_inclusion = 1;
    __uart_handler_inclusion = 1;
    __usb_handler_inclusion = 1;
    __adc_handler_inclusion = 1;
    __timer_handler_inclusion = 1;
}

void button_handler(uint8_t line);

void button_handler(uint8_t line) {
    gpio_set_output_toggle(GPIO_LED_GREEN);
}

static ucdm_addr_t setup_core(ucdm_addr_t ucdm_address) {
    setup_handlers();
    ucdm_init();
    ucdm_address = tm_init(ucdm_address);
    application_gpio_init();
    core_init();
    clock_set_default();
    return ucdm_address;
}


static ucdm_addr_t setup_peripherals(ucdm_addr_t ucdm_address) {
    #if APP_ENABLE_ID
      id_init();
    #endif
    #if APP_ENABLE_ENTROPY
      entropy_init();
    #endif
    #if APP_ENABLE_RTC
      rtc_init();
    #endif
    #if APP_ENABLE_TIME_SYNC
      setup_time_sync();
    #endif
    #if APP_ENABLE_DMA
      dma_init();
    #endif
    #if APP_ENABLE_OUTPUT_BLINK
      start_blink_task();
    #endif
    #if APP_ENABLE_EEPROM
      eeprom_init();
    #endif
    #if APP_ENABLE_USB
      application_usb_init();
    #endif
    #if APP_ENABLE_ADC
      adc_init();
    #endif
    #if APP_ENABLE_TIM15
      timer_init(uC_TIM15_INTFNUM);
    #endif

    #if APP_ENABLE_BCIF
        #if APP_BCIF_TYPE == EBS_INTF_UART
            uart_init(APP_BCIF_INTFNUM);
        #elif APP_BCIF_TYPE == EBS_INTF_USBCDC
            // usbcdc init is handled by application_usb_init()
            // usbcdc_init(APP_BCIF_INTFNUM);
        #endif
    #endif
    #if APP_ENABLE_PRIF
        #if APP_PRIF_TYPE == EBS_INTF_UART
            uart_init(APP_PRIF_INTFNUM);
        #elif APP_PRIF_TYPE == EBS_INTF_USBCDC
            // usbcdc init is handled by application_usb_init()
            // usbcdc_init(APP_PRIF_INTFNUM);
        #endif
    #endif
  
    #if APP_ENABLE_BUTTON
    gpio_conf_interrupt_handler(GPIO_K0, &button_handler);
    gpio_arm_button_interrupt();
    #endif

    return ucdm_address;
}

ucdm_addr_t setup_system(ucdm_addr_t ucdm_address) {
    ucdm_address = setup_core(ucdm_address);
    ucdm_address = setup_peripherals(ucdm_address);
    return ucdm_address;
}

ucdm_addr_t setup_application(ucdm_addr_t ucdm_address) {
    #if APP_ENABLE_MODBUS
      ucdm_address = modbus_init(ucdm_address, MODBUS_DEFAULT_DEVICE_ADDRESS);
    #endif
    return ucdm_address;
}

#ifndef PIO_UNIT_TESTING

int main(void) {
  ucdm_addr_t ucdm_address = 1;
  ucdm_address = setup_system(ucdm_address);
  ucdm_address = setup_application(ucdm_address);
  // start_uart_bare_task();

  // itcm_test();

  setup_adc_demo();
  timer_set_mode(uC_TIM15_INTFNUM, TIMER_MODE_PERIODIC);
  // setup_dma_demo();
    
  while (1)
  {
    #if APP_ENABLE_TIME_CRON
      tm_cron_poll();
    #endif    
    #if APP_ENABLE_USB
      tusb_poll();
    #endif
    #if APP_ENABLE_MODBUS
      modbus_state_machine();
    #endif
    #if APP_ENABLE_ADC
      adc_poll();
    #endif
    #if APP_ENABLE_DMA
      dma_poll(); 
    #endif
    // usbcdc_bare_task();
  }
}

#endif
