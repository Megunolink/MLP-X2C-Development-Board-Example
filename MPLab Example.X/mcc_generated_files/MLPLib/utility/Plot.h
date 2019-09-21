/**
  Plot
	
  Company:
    Microchip Technology Inc.

  File Name:
    Plot.h

  Summary:
    Plot defines different legend for MegunoLink plot. 

  Description:
    This is the generated header file for the Plot driver.

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


#ifndef PLOT_H
#define	PLOT_H

enum Colors 
{ 
  CLR_Red = 'r',
  CLR_Green = 'g', 
  CLR_Blue = 'b',
  CLR_Yellow = 'y',
  CLR_Black = 'k',
  CLR_Magenta = 'm',
  CLR_Cyan = 'c',
  CLR_White = 'w',
  CLR_Default = '\0',
};

enum LineStyle
{
  LINE_Solid = '_',
  LINE_Dashed = '-',
  LINE_Dotted = ':',
  LINE_DashDot = ';',
  LINE_DashDotDot = '%',
  LINE_NoLine = '#',
};

enum MarkerStyle 
{
  MARKER_Square = 's',
  MARKER_Diamond = 'd',
  MARKER_Triangle = '^',
  MARKER_Circle = 'o',
  MARKER_Cross = 'x',
  MARKER_Plus = '+',
  MARKER_Star = '*',
  MARKER_DownwardTriangle = 'v',
  MARKER_NoMarker = 'n',
};



#endif	/* PLOT_H */

