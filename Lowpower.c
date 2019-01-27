#include <Application.h>
#include <Configuration.h>
#include <Project.h>

/*******************************************************************************
* Function Name: System_ManagePower()
********************************************************************************
*
* Summary:
*   This function puts the system in appropriate low power modes based on the 
*   state of BLESS and application power state.
*
* Parameters:
*  none
*
********************************************************************************/
inline void System_ManagePower()
{
    /* Variable declarations */
    CYBLE_BLESS_STATE_T blePower;
    uint8 interruptStatus ;
    
   /* Disable global interrupts to avoid any other tasks from interrupting this section of code*/
    interruptStatus  = CyEnterCriticalSection();
    
    /* Get current state of BLE sub system to check if it has successfully entered deep sleep state */
    blePower = CyBle_GetBleSsState();
    
    /* System can enter DeepSleep only when BLESS and rest of the application are in DeepSleep or equivalent
     * power modes */
    if((blePower == CYBLE_BLESS_STATE_DEEPSLEEP || blePower == CYBLE_BLESS_STATE_ECO_ON) && 
        Application_GetPowerState() == DEEPSLEEP)
    {
        Application_SetPowerState(WAKEUP_DEEPSLEEP);
        
#if DEBUG_ENABLE
        DeepSleep_Write(1);
#endif /* End of #if DEBUG_ENABLE */
        
        CySysPmDeepSleep();
        
#if DEBUG_ENABLE
        DeepSleep_Write(0);
#endif /* End of #if DEBUG_ENABLE */
    }
    else if((blePower != CYBLE_BLESS_STATE_EVENT_CLOSE))
    {
        if(Application_GetPowerState() == DEEPSLEEP)
        {
            Application_SetPowerState(WAKEUP_DEEPSLEEP);
            
            /* change HF clock source from IMO to ECO, as IMO can be stopped to save power */
            CySysClkWriteHfclkDirect(CY_SYS_CLK_HFCLK_ECO); 
            /* stop IMO for reducing power consumption */
            CySysClkImoStop(); 
            /* put the CPU to sleep */
#if DEBUG_ENABLE
            Sleep_Write(1);
#endif /* End of #if DEBUG_ENABLE */      

            CySysPmSleep();
            
#if DEBUG_ENABLE
            Sleep_Write(0);
#endif /* End of #if DEBUG_ENABLE */           
            /* starts execution after waking up, start IMO */
            CySysClkImoStart();
            /* change HF clock source back to IMO */
            CySysClkWriteHfclkDirect(CY_SYS_CLK_HFCLK_IMO);
        }
        else if(Application_GetPowerState() == SLEEP )
        {
            /* If the application is using IMO for its operation, we shouldn't switch over the HFCLK source */
            Application_SetPowerState(WAKEUP_SLEEP);
            
#if DEBUG_ENABLE
            Sleep_Write(1);
#endif /* End of #if DEBUG_ENABLE */     

            CySysPmSleep();
            
#if DEBUG_ENABLE
            Sleep_Write(0);
#endif /* End of #if DEBUG_ENABLE */
        }
    }
    
    /* Enable interrupts */
    CyExitCriticalSection(interruptStatus );
}

/* [] END OF FILE */