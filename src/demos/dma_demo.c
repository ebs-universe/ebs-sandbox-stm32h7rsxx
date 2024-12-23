

#include "dma_demo.h"

uint8_t dd_buffer_1[1024];
uint8_t dd_buffer_2[1024];
uint8_t dd_buffer_3[1024];
uint8_t dd_buffer_4[1024];
uint8_t FASTDATA dd_buffer_5[1024];

static void dd_prefill_buffer(uint8_t *dest, uint16_t length){
    for (uint16_t i=0; i<length; i++){
        *(dest + i) = i;
    }
}

static void dd_reset_buffers(void){
    memset(&dd_buffer_1, 0, 1024);
    memset(&dd_buffer_2, 0, 1024);
    memset(&dd_buffer_3, 0, 1024);
    memset(&dd_buffer_4, 0, 1024);
    dd_prefill_buffer(&dd_buffer_1[0], 1024);
}

void dd_tch(uint8_t token){
    (void)token;
}

void dd_tch_1(uint8_t token){
    dd_tch(token);
}

void dd_tch_2(uint8_t token){
    dd_tch(token);
}

void dd_tch_3(uint8_t token){
    dd_tch(token);
}

void dd_tch_4(uint8_t token){
    dd_tch(token);
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
    dma_memcpy(APP_DMADEMO_MEMCPY_CHANNEL, &dd_buffer_2[0], &dd_buffer_1[0], 1016, &dd_tch_1, 1);
    
    // while (!dma_check_ready(APP_DMADEMO_MEMCPY_CHANNEL)){};

    dma_memcpy(APP_DMADEMO_MEMCPY_CHANNEL, &dd_buffer_3[0], &dd_buffer_2[0], 1016, &dd_tch_2, 2);
    
    /**     
     * Copy from SRAM to DTCM
     * 
     * This works with HPDMA only, with 
     *   - AHB port used to access DTCM (AP=1)  
     *   - AXI port used to access SRAM (AP=0)
     */
    dma_memcpy(APP_DMADEMO_MEMCPY_DTCM_CHANNEL, &dd_buffer_5[0], &dd_buffer_1[0], 1008, &dd_tch_3, 3);
    
    // while (!dma_check_ready(APP_DMADEMO_MEMCPY_DTCM_CHANNEL)){};

    // /**
    //  * Copy from DTCM to SRAM
    //  *  
    //  * This works with HPDMA only, with 
    //  *   - AHB port used to access DTCM (AP=1)
    //  *   - AXI port used to access SRAM (AP=0)
    //  */
    dma_memcpy(APP_DMADEMO_MEMCPY_DTCM_CHANNEL, &dd_buffer_4[0], &dd_buffer_5[0], 1000, &dd_tch_4, 4);

    dma_activate(APP_DMADEMO_MEMCPY_CHANNEL);
    dma_activate(APP_DMADEMO_MEMCPY_DTCM_CHANNEL);
}   
