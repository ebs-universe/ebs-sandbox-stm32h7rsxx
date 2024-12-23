

#define MEMMAP_ENABLE_FASTDATA     1
#define MEMMAP_ENABLE_FASTEXEC     1
#define MEMMAP_ENABLE_SHAREDATA    1

// This can't be changed without changing the startup file. 
// #define MEMMAP_VECTABLE_IN_ITCM    1

#define MEMMAP_FASTDATA_START       0x20000000
#define MEMMAP_FASTDATA_END         0x20020000
#define MEMMAP_FASTEXEC_START       0x00000000
#define MEMMAP_FASTEXEC_END         0x00010000
#define MEMMAP_RAM_START            0x24000000
#define MEMMAP_RAM_END              0x24050000
#define MEMMAP_SHAREDATA_START      0x24060000        
#define MEMMAP_SHAREDATA_END        0x24072000

#define MEMMAP_DMA_LLI_BASE         MEMMAP_SHAREDATA_START
#define MM_DMA_LL                   SHAREDATA

/**
 * ADC DMA Buffer can be put into FASTDATA (DTCM) if the CPU 
 * is going to handle it directly. If it is just going to be 
 * copied out, then SHAREDATA is the better option.
 */ 
#define MM_ADC_DMA_BUFFER           FASTDATA
