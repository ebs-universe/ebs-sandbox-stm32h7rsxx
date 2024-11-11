

#include "usb.h"

#include <stddef.h>
#include <hal/uc/usb.h>
#include <hal/uc/usbcdc.h>

#if BLINK_FOR_USB_STATUS
#include <blink.h>
#endif

#define BLINK_PERIOD_MOUNTED        500
#define BLINK_PERIOD_NOT_MOUNTED    200
#define BLINK_PERIOD_SUSPENDED      5000

#if APP_ENABLE_USB

void tud_mount_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_MOUNTED);
    #endif
    usb_status = USB_ST_ACTIVE;
}

void tud_umount_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_NOT_MOUNTED);
    #endif
    usb_status = USB_ST_DISCONNECTED;
}

void tud_suspend_cb(bool remote_wakeup_en) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_SUSPENDED);
    #endif
    usb_status = USB_ST_SUSPENDED;
}

void tud_resume_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_MOUNTED);
    #endif
    usb_status = USB_ST_ACTIVE;
}

void application_usb_init(void) {
    usb_init();
    tud_init(BOARD_TUD_RHPORT);

    #if uC_USBCDC0_ENABLED
    usbcdc_init(0);
    #endif
    #if uC_USBCDC1_ENABLED
    usbcdc_init(1);
    #endif
    #if uC_USBCDC2_ENABLED
    usbcdc_init(2);
    #endif

    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_NOT_MOUNTED);
    #endif
}

void tusb_task(void){
    #if APP_ENABLE_USB_DEVICE
      tud_task(); 
    #endif
    #if APP_ENABLE_USB_HOST
      tuh_task();
    #endif
}

#endif