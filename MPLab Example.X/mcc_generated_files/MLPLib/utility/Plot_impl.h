/**
  Plot_impl
	
  Company:
    Microchip Technology Inc.

  File Name:
    Plot_impl.h

  Summary:
    Plot_impl defines properties for MegunoLink plot. 

  Description:
    This is the generated header file for the Plot_impl driver.

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

#ifndef PLOT_impl_H
#define	PLOT_impl_H

#include "MegunoLinkProtocol.h"
#include "Plot.h"


void Plot_SetTitle(enum EContext Context, const char *pchTitle);
void Plot_SetXLabel(enum EContext Context, const char *pchLabel);
void Plot_SetYLabel(enum EContext Context, const char *pchLabel);

void Plot_SetSeriesProperties(enum EContext Context, const char *pchSeriesName, enum Colors Color, enum LineStyle Line, unsigned uLineWidth, enum MarkerStyle Marker);
void Plot_SetSeriesProperties_String(enum EContext Context, const char *pchSeriesName, const char *pchSeriesProperties);

void Plot_ClearAll(enum EContext Context);
void Plot_Clear(enum EContext Context, const char *pchSeriesName);

#endif