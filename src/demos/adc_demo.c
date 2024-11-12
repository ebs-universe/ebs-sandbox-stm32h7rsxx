
#include <string.h>
#include "adc_demo.h"

__attribute__((section(".dtcm")))
uint32_t adc_value_count;

__attribute__((section(".dtcm")))
uint16_t adc_values[19];

void adc_result_handler(HAL_BASE_t channel, void * result) {
    adc_values[channel] = *(uint16_t *)result;
    adc_value_count ++;
}


/*
 * This function triggers ADC read of all enabled channels. 
 * 
 * ADC can in principle be triggered by timer, however:
 *   - Timer peripheral implementation pending
 *   - ADC peripheral trigger hookup implementation pending
 * 
 * adc_result_handler is expected to be some application provided function,
 * and adc_values[19] would probably be some (fast) data structure which 
 * can store the data based on intfnum, channel. 
 * 
 * A more complex default handler, which also makes the ADC data available
 * on UCDM, should be implemented. However, note that the ADC interrupt is
 * already marginal and requires -O1 to avoid overrun at the presently 
 * configured conversion speed.
 */
void setup_adc_demo(void){
    memset(adc_values, 0, sizeof(adc_values));
    adc_value_count = 0;
    adc_install_eoc_handler(uC_ADC1_INTFNUM, &adc_result_handler);
    // adc_trigger_scan(uC_ADC1_INTFNUM);
    adc_trigger_autoscan(uC_ADC1_INTFNUM);
}
