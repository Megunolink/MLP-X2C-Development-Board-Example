/**
  MLP Update
	
  Company:
    Microchip Technology Inc.

  File Name:
    MLPUpdate.h

  Summary:
    MLP Update sends data to MegunoLink visualizers depending on the Trigger Period.

  Description:
    This is the generated header file for the MLP Update driver.

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

#ifndef MLPUPDATE_H
#define	MLPUPDATE_H

#include "../mcc.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

/**
  @Summary
    Initializes the MLP Update module.

  @Description
    This function initializes the TMR ISR.
    This function must be called before any other MLP Update function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

*/
void MLPUpdate_Initialize(void);

/**
  @Summary
    MLP Refresh

  @Description
    This routine is called during the runtime

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void MLP_Refresh(void);

/**
  @Summary
    Set MLP Update Handler

  @Description
    This sets the function to be called during the update

  @Preconditions
    None

  @Param
    Address of function to be set

  @Returns
    None
*/
void MLP_SetUpdate(void(* MLP_UpdateHandler)(void));

/**
  @Summary
    MLP Update Handler

  @Description
    This is a function pointer to the function that will be called during the Update

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
extern void (*MLP_UpdateHandler)(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MLPUPDATE_H */

