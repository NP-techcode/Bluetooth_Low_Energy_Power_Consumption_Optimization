#if !defined(LOW_POWER_H)
#define LOW_POWER_H
    
#include <Configuration.h>

/*****************************************************
*                  Enums and macros
*****************************************************/    
typedef enum {
    WAKEUP_SLEEP,
    WAKEUP_DEEPSLEEP,
    ACTIVE,
    SLEEP,
    DEEPSLEEP
} POWER_MODE_T;    
    
#if TX_RX_GPIO_ENABLE
#define CYREG_RADIO_TX_RX_MUX_REGISTER          0x40030008
#define RADIO_TX_RX_SEL                         0x0330
#define RADIO_TX_RX_MUX_MASK                    0x00003F3F
#define BLESS_MUX_INPUT_MASK                    0x80000203    
#endif /* End of #if TX_RX_GPIO_ENABLE */

/*****************************************************
*                  Function declarations
*****************************************************/ 
void System_ManagePower();

#endif /* End of #if !defined(LOW_POWER_H) */

/* [] END OF FILE */