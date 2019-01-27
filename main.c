#include <Application.h>
#include <BLE Interface.h>
#include <Configuration.h>
#include <Init.h>
#include <LowPower.h>
#include <project.h>

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*        System entry point. This calls the BLE and other peripheral Component
* APIs for achieving the desired system behaviour
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main()
{
    /* This function will initialize all the Components and system variables */
	InitializeSystem();

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    while(1)
    {
        /***********************************************************************
        *  Process all the pending BLE events in the stack
        ***********************************************************************/
        BLE_Run();
         
        /***********************************************************************
        *  Put BLE sub system in DeepSleep mode when it is idle
        ***********************************************************************/ 
        BLE_ManagePower();
    
        /***********************************************************************
        *  Run your application specific code here
        ***********************************************************************/  
        if(Application_GetPowerState() == ACTIVE)
        {
            Application_Run();
        }
        
        /***********************************************************************
        *  Process application and system power modes 
        ***********************************************************************/
        Application_ManagePower();   
        
        System_ManagePower();
        
    }	/* End of while(1) */
    
} /* End of main */

/* [] END OF FILE */