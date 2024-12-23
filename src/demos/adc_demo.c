
#include <string.h>
#include "adc_demo.h"
#include <platform/sections.h>


#if uC_ADC1_DM_MODE == ADC_DM_INTERRUPT
uint32_t adc_value_count FASTDATA;
uint16_t adc_values[19]  FASTDATA;

FASTEXEC
void adc_result_handler(HAL_BASE_t channel, void * result) {
    adc_values[channel] = *(uint16_t *)result;
    adc_value_count ++;
}
#endif

/*
 * This function triggers ADC read of all enabled channels. 
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
    #if uC_ADC1_DM_MODE == ADC_DM_INTERRUPT
    memset(adc_values, 0, sizeof(adc_values));
    adc_value_count = 0;
    adc_install_eoc_handler(uC_ADC1_INTFNUM, &adc_result_handler);
    #endif
    adc_arm_trigger(uC_ADC1_INTFNUM);       
    // adc_trigger_scan(uC_ADC1_INTFNUM);
    // adc_trigger_autoscan(uC_ADC1_INTFNUM);
}
