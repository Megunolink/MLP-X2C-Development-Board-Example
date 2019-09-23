/** ************************************************************************
 * Example MegunoLink program for X2C+ Development Board. 
 * 
 * Description:
 * Demonstrates sending data to a MegunoLink plot and receiving a command
 * from an Interface Panel. Periodically the current value of the on-board
 * POT is sent to a time-plot. Commands of the form !SetLED N S\r\n are
 * processed to control the LEDs on the board. N specifies the LED [1,4]
 * and S specifies the state (0 => off, 1 => on). 
 * 
 * Open the MegunoLink project file "X2C+ Example.mlpz" to graph the data
 * and send serial commands. 
 * 
 * For a free trial of MegunoLink, visit: https://www.megunolink.com
 * For more information, visit:
 * https://www.megunolink.com/documentation/embedded-libraries/megunolink-protocol-library-for-mplab-x/
 * 
 * Number Eight Innovation 2019. 
 * The MIT License applies to this file. 
 * ************************************************************************ */

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/MLPLib/CommandHandler.h"
#include "mcc_generated_files/MLPLib/MLPUpdate.h"

/* -----------------------------------------------------------------
 Serial command handlers. 
 * -----------------------------------------------------------------  */

/* Handle a SetLED command. 
 * This command takes two parameters: the LED number [1,4] and the
 * desired state of the LED (0 => off, 1 => on). The LED state is
 * updated accordingly. */
void Cmd_SetLED(TParameters *p)
{
    int nLED = CH_NextParameterAsInteger(p, -1);
    int nState = CH_NextParameterAsInteger(p, 1);
    
    switch (nLED)
    {
        case 1:
            if (nState)
            {
                IO_RC4_SetHigh();
            }
            else
            {
                IO_RC4_SetLow();
            }
            break;
            
        case 2:
            if (nState)
            {
                IO_RC5_SetHigh();
            }
            else
            {
                IO_RC5_SetLow();
            }
            break;

        case 3:
            if (nState)
            {
                IO_RC6_SetHigh();
            }
            else
            {
                IO_RC6_SetLow();
            }
            break;

        case 4:
            if (nState)
            {
                IO_RC7_SetHigh();
            }
            else
            {
                IO_RC7_SetLow();
            }
            break;
    }
}

/* -----------------------------------------------------------------
 Main application
 * -----------------------------------------------------------------  */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    // Initialize the analog-to-digital converter so we can read the POT.
    ADCC_Initialize();
    
    // Initialize millisecond timer
    MLPUpdate_Initialize();
    
    // Setup a command handler to decode and dispatch serial commands. 
    struct CommandHandlerContext CommandContext;
    CH_Init(&CommandContext);
    CH_AddCommand(&CommandContext, "SetLED", Cmd_SetLED);
    
    // Access global counter which increments every millisecond. 
    extern uint32_t MillisecondCounter;
    uint32_t LastPlotTime = 0;
    
    while (1)
    {
        // Handle serial commands. 
        CH_Process(&CommandContext);
        
        // Periodically send the POT value to MegunoLink.
        uint32_t Now = MillisecondCounter;
        if (Now - LastPlotTime > 500)
        {
            LastPlotTime = Now;
            
            ADCC_StartConversion(channel_ANA1);
            while (!ADCC_IsConversionDone())
            {
                // Wait for conversion to complete. 
            }
            adc_result_t PotValue = ADCC_GetConversionResult();
            TimePlot_Send_Int("Pot", PotValue);
        }
    }
}
/**
 End of File
*/