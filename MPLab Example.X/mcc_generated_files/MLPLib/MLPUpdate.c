/**
  MLP Update
	
  Company:
    Microchip Technology Inc.

  File Name:
    MLPUpdate.c

  Summary:
    MLP Update sends data to MegunoLink visualizers depending on the Trigger Period.

  Description:
    This is the generated source file for the MLP Update driver.

*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "MLPUpdate.h"
    
uint16_t TriggerPeriod = 30000;
uint32_t LastTriggerTime = -30000;
uint32_t MillisecondCounter = 0;

void (*MLP_Update)(void);
void Timer_ISR(void);
uint32_t Millis(void);

uint32_t Millis(void){
  return MillisecondCounter;
}

void Timer_ISR(void){
    MillisecondCounter++;
}

void MLPUpdate_Initialize(void) {
    TMR0_SetInterruptHandler(Timer_ISR);
}

void MLP_Refresh(void){
    if((Millis() - LastTriggerTime) > TriggerPeriod){
        printf("%lu\n", Millis());
        LastTriggerTime = Millis();
        MLP_Update();
    }
}

void MLP_SetUpdate(void(* MLP_UpdateHandler)(void)){
    MLP_Update = MLP_UpdateHandler;
}
