

#define uC_NVIC_PRIORITY_CONF   NVIC_PRIORITYGROUP_2

#define PRIO_INT_HIGHEST        0
#define PRIO_INT_HIGH           1
#define PRIO_INT_NORMAL         2
#define PRIO_INT_LOW            3
#define PRIO_NONE               0xFF

typedef enum {
    _PRIO_INT_HIGHEST = PRIO_INT_HIGHEST,
    _PRIO_INT_HIGH    = PRIO_INT_HIGH,
    _PRIO_INT_NORMAL  = PRIO_INT_NORMAL,
    _PRIO_INT_LOW     = PRIO_INT_LOW,
    _PRIO_NONE        = PRIO_NONE
} EBS_PRIORITY_t;

#define PRIO_SYSTICK            PRIO_INT_LOW
#define PRIO_ADC                PRIO_INT_HIGHEST
#define PRIO_ENTROPY            PRIO_INT_LOW

#define PRIO_GPIO0              PRIO_INT_NORMAL         
#define PRIO_GPIO1              PRIO_INT_NORMAL
#define PRIO_GPIO2              PRIO_INT_NORMAL
#define PRIO_GPIO3              PRIO_INT_NORMAL
#define PRIO_GPIO4              PRIO_INT_NORMAL
#define PRIO_GPIO5              PRIO_INT_NORMAL
#define PRIO_GPIO6              PRIO_INT_NORMAL
#define PRIO_GPIO7              PRIO_INT_NORMAL
#define PRIO_GPIO8              PRIO_INT_NORMAL
#define PRIO_GPIO9              PRIO_INT_NORMAL
#define PRIO_GPIO10             PRIO_INT_NORMAL
#define PRIO_GPIO11             PRIO_INT_NORMAL
#define PRIO_GPIO12             PRIO_INT_NORMAL
#define PRIO_GPIO13             PRIO_INT_NORMAL
#define PRIO_GPIO14             PRIO_INT_NORMAL
#define PRIO_GPIO15             PRIO_INT_NORMAL

#define PRIO_TIMER15            PRIO_INT_LOW

#define PRIO_USART1             PRIO_INT_NORMAL
#define PRIO_USART2             PRIO_INT_NORMAL
#define PRIO_USART3             PRIO_INT_NORMAL
#define PRIO_USART4             PRIO_INT_NORMAL
#define PRIO_USART5             PRIO_INT_NORMAL
#define PRIO_USART6             PRIO_INT_NORMAL
#define PRIO_USART7             PRIO_INT_NORMAL

#define PRIO_USB                PRIO_INT_NORMAL

#define PRIO_DMA1_CH0           PRIO_NONE
#define PRIO_DMA1_CH1           PRIO_NONE
#define PRIO_DMA1_CH2           PRIO_NONE
#define PRIO_DMA1_CH3           PRIO_NONE
#define PRIO_DMA1_CH4           PRIO_NONE
#define PRIO_DMA1_CH5           PRIO_NONE
#define PRIO_DMA1_CH6           PRIO_NONE
#define PRIO_DMA1_CH7           PRIO_NONE
#define PRIO_DMA1_CH8           PRIO_NONE
#define PRIO_DMA1_CH9           PRIO_NONE
#define PRIO_DMA1_CH10          PRIO_NONE
#define PRIO_DMA1_CH11          PRIO_NONE
#define PRIO_DMA1_CH12          PRIO_NONE
#define PRIO_DMA1_CH13          PRIO_NONE
#define PRIO_DMA1_CH14          PRIO_NONE
#define PRIO_DMA1_CH15          PRIO_NONE

#define PRIO_DMA2_CH0           PRIO_NONE
#define PRIO_DMA2_CH1           PRIO_NONE
#define PRIO_DMA2_CH2           PRIO_NONE
#define PRIO_DMA2_CH3           PRIO_NONE
#define PRIO_DMA2_CH4           PRIO_NONE
#define PRIO_DMA2_CH5           PRIO_NONE
#define PRIO_DMA2_CH6           PRIO_NONE
#define PRIO_DMA2_CH7           PRIO_NONE
#define PRIO_DMA2_CH8           PRIO_NONE
#define PRIO_DMA2_CH9           PRIO_NONE
#define PRIO_DMA2_CH10          PRIO_NONE
#define PRIO_DMA2_CH11          PRIO_NONE
#define PRIO_DMA2_CH12          PRIO_NONE
#define PRIO_DMA2_CH13          PRIO_NONE
#define PRIO_DMA2_CH14          PRIO_NONE
#define PRIO_DMA2_CH15          PRIO_NONE

