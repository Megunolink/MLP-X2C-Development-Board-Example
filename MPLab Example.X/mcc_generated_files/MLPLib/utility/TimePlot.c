/**
  Time Plot
	
  Company:
    Microchip Technology Inc.

  File Name:
    TimePlot.c

  Summary:
    Time Plot sends data to a MegunoLink Time Plot visualizer.   

  Description:
    This is the generated source file for the Time Plot driver.

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

#include "TimePlot.h"

void TimePlot_Send_Int(const char *pchSeriesName, int nValue)
{
  MLP_SendDataHeader(MLP_TimePlot, NULL, "DATA");
  MLP_Print_String(pchSeriesName);
  MLP_Print_Separator();
  MLP_Print_Char('T');
  MLP_Print_Separator();
  MLP_Print_Int(nValue);
  MLP_SendTail();
}

void TimePlot_Send_Long(const char *pchSeriesName, long nValue)
{
  MLP_SendDataHeader(MLP_TimePlot, NULL, "DATA");
  MLP_Print_String(pchSeriesName);
  MLP_Print_Separator();
  MLP_Print_Char('T');
  MLP_Print_Separator();
  MLP_Print_Long(nValue);
  MLP_SendTail();
}

void TimePlot_Send_Double(const char *pchSeriesName, double nValue)
{
  MLP_SendDataHeader(MLP_TimePlot, NULL, "DATA");
  MLP_Print_String(pchSeriesName);
  MLP_Print_Separator();
  MLP_Print_Char('T');
  MLP_Print_Separator();
  MLP_Print_Double(nValue);
  MLP_SendTail();
}


