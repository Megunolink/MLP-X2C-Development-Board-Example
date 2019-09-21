/**
  Megunolink Protocol
	
  Company:
    Microchip Technology Inc.

  File Name:
    MegunolinkProtocol.h

  Summary:
    Megunolink Protocol

  Description:
    This is the generated header file for the Megunolink Protocol driver.

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

#ifndef _MEGUNOLINKPROTOCOL_H
#define _MEGUNOLINKPROTOCOL_H

#pragma once
#include <stdio.h>


typedef enum EContext
{
  MLP_Table,
  MLP_TimePlot,
  MLP_XYPlot,
  MLP_MessageMonitor,
  MLP_Map,
  MLP_InterfacePanel,
  MLP_Test, 
} TEContext;

void MLP_SendDataHeader(enum EContext Context, const char *pchChannel, const char *pchCommand);
void MLP_Print_Int(int nValue);
void MLP_Print_UInt(unsigned uValue);
void MLP_Print_ULong(unsigned long ulValue);
void MLP_Print_Long(long nValue);
void MLP_Print_Double(double dLatitude);

void MLP_Print_String(const char *pch);
void MLP_Print_Char(char ch);
void MLP_Print_Separator();
void MLP_SendTail();

int MLP_TryReadCharacter();

#endif