/**
  Plot_impl
	
  Company:
    Microchip Technology Inc.

  File Name:
    Plot_impl.c

  Summary:
    Plot_impl defines properties for MegunoLink plot. 

  Description:
    This is the generated source file for the Plot_impl driver.

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

#include "Plot_impl.h"

void SendProperty(enum EContext Context, const char *pchParameter, const char *pchValue)
{
  MLP_SendDataHeader(Context, NULL, "SET");
  MLP_Print_String(pchParameter);
  MLP_Print_Char('=');
  MLP_Print_String(pchValue);
  MLP_SendTail();
}

void SendSeriesProperties_Core(enum EContext Context, const char *pchSeriesName, const char *pchProperties)
{
  MLP_SendDataHeader(Context, NULL, "STYLE");
  MLP_Print_String(pchSeriesName);
  MLP_Print_Char(':');
  MLP_Print_String(pchProperties);
}


void Plot_SetTitle(enum EContext Context, const char *pchTitle)
{
  SendProperty(Context, "title", pchTitle);
}

void Plot_SetXLabel(enum EContext Context, const char *pchLabel)
{
  SendProperty(Context, "x-label", pchLabel);
}

void Plot_SetYLabel(enum EContext Context, const char *pchLabel)
{
  SendProperty(Context, "y-label", pchLabel);
}

void Plot_SetSeriesProperties(enum EContext Context, const char *pchSeriesName, enum Colors Color, enum LineStyle Line, unsigned uLineWidth, enum MarkerStyle Marker)
{
  char chData[4];
  chData[0] = Color;
  chData[1] = Marker;
  chData[2] = Line;
  chData[3] = '\0';
  
  SendSeriesProperties_Core(Context, pchSeriesName, chData);
  MLP_Print_UInt(uLineWidth);
  MLP_SendTail();
}

void Plot_SetSeriesProperties_String(enum EContext Context, const char *pchSeriesName, const char *pchSeriesProperties)
{
  SendSeriesProperties_Core(Context, pchSeriesName, pchSeriesProperties);
  MLP_SendTail();
}

void Plot_ClearAll(enum EContext Context)
{
  MLP_SendDataHeader(Context, NULL, "CLEAR");
  MLP_SendTail();
}

void Plot_Clear(enum EContext Context, const char *pchSeriesName)
{
  MLP_SendDataHeader(Context, NULL, "CLEAR");
  MLP_Print_String(pchSeriesName);
  MLP_SendTail();
}

