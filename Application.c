

#include <Application.h>
#include <LowPower.h>

/******************************************************************************
*                           Global variables
*******************************************************************************/
POWER_MODE_T applicationPowerState = ACTIVE;

/*******************************************************************************
* Function Name: Application_ManagePower
********************************************************************************
*
* Summary:
* This function manages the different power modes and transition between the
* power modes based on the state of the application and peripherals
*
* Parameters:  
*  None
*
* Return: 
*  None
*******************************************************************************/
inline void Application_ManagePower(void)
{
    switch(applicationPowerState)
    {
        case ACTIVE: /* Don't need to do anything */
        break;
        
        case WAKEUP_SLEEP: 
        /***********************************************************************
        * Add your code to wakeup the application Components from sleep here.
        * Mostly this state will be unused.
        ************************************************************************/
            applicationPowerState = ACTIVE;
        break;
        
        case WAKEUP_DEEPSLEEP: 
        /***********************************************************************
        * Add your code to wake up the application layer Components 
        ************************************************************************/
            applicationPowerState = ACTIVE;
        break;
        
        case SLEEP: 
        /***********************************************************************
        * Add your code to place the application Components to sleep here.
        * Mostly this state will be unused.
        ************************************************************************/        
        break;
        
        case DEEPSLEEP:
        /***********************************************************************
        * Add your code to place the application Components to DeepSleep here 
        ************************************************************************/       
        break;
    }
}

/*******************************************************************************
* Function Name: Application_Run
********************************************************************************
*
* Summary:
* This is the main application run loop. Most of the non-BLE part of the
* application must be done within this function. A template implementation for 
* your application is provided for now.
*
* Parameters:  
*  None
*
* Return: 
*  None
*******************************************************************************/
void Application_Run(void)
{
    /***********************************************************************
    *  Place your application code here
    ************************************************************************/  
   
    if(1) /* If you are done with everything, then DeepSleep */
    {
        applicationPowerState = DEEPSLEEP;
    }
}

/*******************************************************************************
* Function Name: Application_GetPowerState
********************************************************************************
*
* Summary:
* Returns if the application is active, waiting to be or in Sleep or DeepSleep
* mode
*
* Parameters:  
*  None
*
* Return: 
*  Application power state
*******************************************************************************/
POWER_MODE_T Application_GetPowerState(void)
{
    return applicationPowerState;
}

/*******************************************************************************
* Function Name: Application_SetPowerState
********************************************************************************
*
* Summary:
* Sets the state of the application power mode. This function will be used by
* the peripherals or application run loop or system power manager to indicate
* a power state change
*
* Parameters:  
*  power state to be set
*
* Return: 
*  None
*******************************************************************************/
void Application_SetPowerState(POWER_MODE_T pwrState)
{
    applicationPowerState = pwrState;
}

/* [] END OF FILE */