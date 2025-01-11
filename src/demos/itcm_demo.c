
#include <hal/uc/gpio.h>

#pragma GCC push_options
#pragma GCC optimize("O0")
__attribute__((section(".itcm")))
void itcm_demo(void) {
  gpio_set_output_high(GPIO_LED_GREEN);
}
#pragma GCC pop_options
