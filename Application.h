Description - Contains all the application layer macros and function 
* declarations
********************************************************************************/
#if !defined(APPLICATION_H)
#define APPLICATION_H

#include <LowPower.h>    
#include <project.h>
	
/*****************************************************
*                  Configuration flags
*****************************************************/
#if TX_RX_GPIO_ENABLE
#define CYREG_RADIO_TX_RX_MUX_REGISTER          0x40030008
#define RADIO_TX_RX_SEL                         0x0330
#define RADIO_TX_RX_MUX_MASK                    0x00003F3F
#define BLESS_MUX_INPUT_MASK                    0x80000203    
#endif /* End of #if TX_RX_GPIO_ENABLE */

/*****************************************************
*                  Function declarations
*****************************************************/
void Application_Run(void);
void Application_ManagePower(void);
POWER_MODE_T Application_GetPowerState(void);
void Application_SetPowerState(POWER_MODE_T pwrMode);

#endif /* End of #if !defined(APPLICATION_H) */

/* [] END OF FILE */