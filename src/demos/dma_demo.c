

#include "dma_demo.h"

uint8_t dd_buffer_1[256];
uint8_t dd_buffer_2[256];
uint8_t dd_buffer_3[256] FASTDATA;
uint8_t dd_buffer_4[256];

void dd_prefill_buffer(uint8_t *dest, uint16_t length){
    for (uint16_t i=0; i<length; i++){
        *(dest + i) = i;
    }
}

void dd_copy_buffer(HAL_BASE_t intfnum, void *src, void *dst, uint16_t len, uint8_t src_ap, uint8_t dst_ap){
    /**
     * The application would generally be expected to implement this function 
     * for each DMA use. This is where the specifics of the DMA transfer are to 
     * be configured. The HAL constants and structures allow a degree of 
     * standardization to be had, but in general expect these to be highly 
     * platform dependent. 
     * 
     * Some helper functions may be added to the HAL to provide an actually 
     * standardized interface to some of the DMA configuration in the future. 
     * It is unclear if the use of the DMA abstraction layer is of any real 
     * value. Most likely, further standardization will be needed to provide
     * any meaningful benefit.
     * 
     *  - AP 0 is AXI for HPDMA, AHB for GPDMA
     *  - DTCM can be accessed only using AHB with HPDMA. To read / write 
     *    DTCM, use a HPDMA channel (DMA1) and add DMA_OPT_AP to the 
     *    appropriate src_opts or dst_opts
     *  - Not enabling any exchange / reordering
     *  - Using 4 byte width
     *  - Trigger is not used
     *  - Software Request is used
     *  - length needs to be a multiple of the appropriate beat / burst size, 
     *    a user error is generated if not.  
     *  - Implementation hardcodes channels to privileged mode
     */
    dma_xfer_t xfer = {
        .src = (HAL_ADDRESS_t)src, 
        .dst = (HAL_ADDRESS_t)dst,
        .size = len,
        .type = DMA_XFER_MEMORY_MEMORY,         
        .src_opts = (0b10 << DMA_OPT_WIDTH_POS) | src_ap,
        .dst_opts = (0b10 << DMA_OPT_WIDTH_POS) | dst_ap,
        .src_burst_len = 8,
        .dst_burst_len = 8,
        .dst_offset_incr = 0,
        .src_offset_incr = 0,
        .repeats = 0
    };  

    dma_flow_control_t fc = {
        .req_type = DMA_REQ_SOFTWARE,
        .req_sel = 0,               
        .opts = DMA_OPT_REQ_BLOCK,
        .trig_sel = 0
    };
    
    dma_setup_xfer(intfnum, &xfer);
    dma_setup_flow_control(intfnum, &fc);
    dma_trigger_arm(intfnum);
    dma_trigger(intfnum);
}

void dd_reset_buffers(void){
    memset(&dd_buffer_1, 0, 256);
    memset(&dd_buffer_2, 0, 256);
    memset(&dd_buffer_3, 0, 256);
    memset(&dd_buffer_4, 0, 256);
    dd_prefill_buffer(&dd_buffer_1[0], 256);
}

// DMA1: HPDMA, DMA2: GPDMA

void setup_dma_demo(void){  
    dd_reset_buffers();

    /**
     * Copy from SRAM to SRAM
     *  
     * This works with either DMA. 
     * When HPDMA is used, the AXI port must be used (AP=0)
     */
    dd_copy_buffer(uC_DMA2_CH0_INTFNUM, &dd_buffer_1[0], &dd_buffer_2[0], 248, 0, 0);
    
    /** 
     * Copy from SRAM to DTCM
     * 
     * This works with HPDMA only, with 
     *   - AHB port used to access DTCM (AP=1)
     *   - AXI port used to access SRAM (AP=0)
     */
    dd_copy_buffer(uC_DMA1_CH0_INTFNUM, &dd_buffer_1[0], &dd_buffer_3[0], 248, 0, DMA_OPT_AP);
    
    // Wait for the previous to finish
    while (!dma_check_ready(uC_DMA1_CH0_INTFNUM)){};

    // /**
    //  * Copy from DTCM to SRAM
    //  *  
    //  * This works with HPDMA only, with 
    //  *   - AHB port used to access DTCM (AP=1)
    //  *   - AXI port used to access SRAM (AP=0)
    //  */
    dd_copy_buffer(uC_DMA1_CH0_INTFNUM, &dd_buffer_3[0], &dd_buffer_4[0], 240, DMA_OPT_AP, 0);
}
