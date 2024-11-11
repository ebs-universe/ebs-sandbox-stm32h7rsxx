

#include <application.h>
#include <tusb.h>
#include "usb_task.h"
#include <hal/uc/usb.h>
#include <hal/uc/usbcdc.h>

#if APP_ENABLE_USB

uint8_t message[] = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
uint8_t appl = 0;
uint8_t usb_read_buf[64];

static void cdc_read_task(void)
{
  if ( appl ) {
    return;
  }
  if ( usbcdc_population_rxb(0) )
  {
    usbcdc_read(0, usb_read_buf, 64);
    appl = usb_read_buf[0];
    usbcdc_putc(0, appl, 0x00, 0x00);
    return;
  }
}

static void cdc_write_task(void) {
  if (appl == 'a' && usb_status == USB_ST_ACTIVE) {
      if (usbcdc_reqlock(0, sizeof(message) - 1, 0x00)){
          usbcdc_write(0, message, sizeof(message) - 1, 0x00);
      }
    }
}

void usbcdc_bare_task(void){
    #if APP_ENABLE_USB_DEVICE
      cdc_read_task();
      cdc_write_task();
    #endif
}

#endif
