#if !defined(BLE_INTERFACE_H)
#define BLE_INTERFACE_H
    
#include <project.h>    
    
/*****************************************************
*                  Enums and macros
*****************************************************/    
#define CRYSTAL_STARTUP_TIME                        (15u) /* Startup time = 15 * 61us */    
    
#define MINIMUM_CONNECTION_INTERVAL                 (790u) /* 790 * 1.25 = 987.5ms */
#define MAXIMUM_CONNECTION_INTERVAL                 (800u) /* 800 * 1.25 = 1000ms */
#define SLAVE_LATENCY                               (0u)   /* No slave latency */
#define SUPERVISION_TIMEOUT                         (500u) /* Supervision timeout of 5 seconds */    
    
#define INITIAL_HEART_RATE_VALUE                    (60u) /* Initial value of notification to be used */    
    
/*****************************************************
*                  Function declarations
*****************************************************/    
CYBLE_API_RESULT_T BLE_Engine_Start(void);
void BLE_Run(void);
#define BLE_ManagePower()                           CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP)
    
#endif /* End of #if !defined(BLE_INTERFACE_H) */

/* [] END OF FILE */