

#include "iomap.h"
#include <hal/uc/gpio.h>


static void gpio_init_board_leds(void){
    gpio_conf_output(GPIO_LED1);
    gpio_conf_output(GPIO_LED2);
    gpio_conf_output(GPIO_LED3);

    gpio_conf_outmode_pp(GPIO_LED1);
    gpio_conf_outmode_pp(GPIO_LED2);
    gpio_conf_outmode_pp(GPIO_LED3);

    gpio_conf_speed(GPIO_LED1, GPIO_SPEED_FREQ_LOW);
    gpio_conf_speed(GPIO_LED2, GPIO_SPEED_FREQ_LOW);    
    gpio_conf_speed(GPIO_LED3, GPIO_SPEED_FREQ_LOW);    
    
    gpio_set_output_low(GPIO_LED1);
    gpio_set_output_low(GPIO_LED2);
    gpio_set_output_low(GPIO_LED3);
}

static void gpio_init_board_buttons(void){
    gpio_conf_input(GPIO_K0);
    gpio_conf_pullup(GPIO_K0);
    gpio_conf_interrupt(GPIO_K0, GPIO_INT_EDGE_FALLING);
}

void gpio_arm_button_interrupt(void){
    gpio_interrupt_arm(GPIO_K0);
}

void gpio_disarm_button_interrupt(void){
    gpio_interrupt_disarm(GPIO_K0);
}

static void gpio_init_bcif(void) {
    gpio_conf_periph(GPIO_BCTX, GPIO_AF7_USART3);
    gpio_conf_periph(GPIO_BCRX, GPIO_AF7_USART3);
}

static void gpio_init_adc(void) {
    // ADC inputs exposed on arduino connector configured. 
    #if APP_ENABLE_AIN0
    gpio_conf_analog(GPIO_AIN0);
    #endif
    #if APP_ENABLE_AIN1
    gpio_conf_analog(GPIO_AIN1);
    #endif
    #if APP_ENABLE_AIN2
    gpio_conf_analog(GPIO_AIN2);
    #endif
    #if APP_ENABLE_AIN3
    gpio_conf_analog(GPIO_AIN3);
    #endif
    #if APP_ENABLE_AIN4
    gpio_conf_analog(GPIO_AIN4);
    #endif
    #if APP_ENABLE_AIN5
    gpio_conf_analog(GPIO_AIN5);
    #endif
    #if APP_ENABLE_AIN6
    gpio_conf_analog(GPIO_AIN6);
    #endif
    #if APP_ENABLE_AIN7
    gpio_conf_analog(GPIO_AIN7);
    #endif
    #if APP_ENABLE_AIN8
    gpio_conf_analog(GPIO_AIN8);
    #endif
    #if APP_ENABLE_AIN9
    gpio_conf_analog(GPIO_AIN9);
    #endif
    #if APP_ENABLE_AIN10
    gpio_conf_analog(GPIO_AIN10);
    #endif
    #if APP_ENABLE_AIN11
    gpio_conf_analog(GPIO_AIN11);
    #endif
    #if APP_ENABLE_AIN12
    gpio_conf_analog(GPIO_AIN12);
    #endif
    #if APP_ENABLE_AIN13
    gpio_conf_analog(GPIO_AIN13);
    #endif
    #if APP_ENABLE_AIN14
    gpio_conf_analog(GPIO_AIN14);
    #endif
    #if APP_ENABLE_AIN15
    gpio_conf_analog(GPIO_AIN15);
    #endif
    #if APP_ENABLE_AIN18
    gpio_conf_analog(GPIO_AIN18);
    #endif
}

void application_gpio_init (void){
    gpio_init();
    gpio_init_board_leds();
    gpio_init_board_buttons();
    gpio_init_bcif();
    gpio_init_adc();
}
