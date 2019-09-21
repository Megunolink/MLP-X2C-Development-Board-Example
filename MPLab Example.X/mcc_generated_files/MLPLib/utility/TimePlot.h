/**
  Time Plot
	
  Company:
    Microchip Technology Inc.

  File Name:
    TimePlot.h
  Summary:
    Time Plot sends data to a MegunoLink Time Plot visualizer.   

  Description:
    This is the generated header file for the Time Plot driver.

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

#ifndef MLP_TIME_PLOT_H
#define MLP_TIME_PLOT_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include "MegunoLinkProtocol.h"
#include "Plot_impl.h"

/*!
 * @brief Send an integer value to a MegunoLink Time Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink Time Plot visualizer. The value is 
 * added to the end of the plot with the current time used for the x-axis. 
 * \param pchSeriesName Name of the table row
 * \param nValue Value to send
 * */
void TimePlot_Send_Int(const char *pchSeriesName, int nValue);

/*!
 * @brief Send a long integer value to a MegunoLink Time Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink Time Plot visualizer. The value is 
 * added to the end of the plot with the current time used for the x-axis. 
 * \param pchSeriesName Name of the table row
 * \param nValue Value to send
 * */
void TimePlot_Send_Long(const char *pchSeriesName, long nValue);

/*!
 * @brief Send a doublevalue to a MegunoLink Time Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink Time Plot visualizer. The value is 
 * added to the end of the plot with the current time used for the x-axis. 
 * \param pchSeriesName Name of the table row
 * \param nValue Value to send
 * */
void TimePlot_Send_Double(const char *pchSeriesName, double nValue);

/*!
 * @brief Sets the plot title
 * 
 * Sets the time title of a time plot. 
 * \param pchTitle The new title of the plot (null terminated string). 
 * */
static inline void TimePlot_SetTitle(const char *pchTitle)
{
  Plot_SetTitle(MLP_TimePlot, pchTitle);
}

/*!
 * @brief Set the label for the x-axis 
 * \param pchLabel A null terminated string label for the plot's x-axis
 * (horizontal axis). 
 * */
static inline void TimePlot_SetXLabel(const char *pchLabel)
{
  Plot_SetXLabel(MLP_TimePlot, pchLabel);
}

/*!
 * @brief Set the label for the y-axis
 * \param pchLabel A null terminated string label for the plot's y-axis
 * (vertical axis). 
 * */
static inline void TimePlot_SetYLabel(const char *pchLabel)
{
  Plot_SetYLabel(MLP_TimePlot, pchLabel);
}

/*!
 * @brief Sets the series properties
 * 
 * Sets the color, line style and line width for a series.
 * \param pchSeriesName Name of the series to change (null terminated string)
 * \param Color New colour of the series. 
 * \param Line New style for the line
 * \param uLineWidth Width of the line used to draw the series
 * \param Marker Style to use for drawing series points.
 * */
static inline void TimePlot_SetSeriesProperties(const char *pchSeriesName, enum Colors Color, enum LineStyle Line, unsigned uLineWidth, enum MarkerStyle Marker)
{
  Plot_SetSeriesProperties(MLP_TimePlot, pchSeriesName, Color, Line, uLineWidth, Marker);
}

/*!
 * @brief Sets the series properties
 * 
 * Sets the color, line style and line width for a series from a single string.
 * Not all properties are required; only those that are present are updated. 
 * \param pchSeriesName Name of the series to change (null terminated string)
 * \param pchSeriesProperties Null terminated style characters. One or more of 
 * the following characters to set:
 * color: r (red), g (green), b (blue), y (yellow), k (black), m (magenta), 
 * c (cyan), w (white)
 * line-style: _ (solid line), - (dashed line), : (dotted line), ; (dash dot
 * line), % (dash dot dot line), # (no line); a number following the line style 
 * sets the line width
 * marker-style: s (square), d (diamond), ^ (triangle), o (circle), x (cross),
 * + (plus sign), * (star), v (downward triangle), n (no symbol). 
 * a number following the marker-style sets the marker size. 
 * */
static inline void TimePlot_SetSeriesProperties_String(const char *pchSeriesName, const char *pchSeriesProperties)
{
  Plot_SetSeriesProperties_String(MLP_TimePlot, pchSeriesName, pchSeriesProperties);
}

/*!
 * @brief Clears all series from the time plot
 * */
static inline void TimePlot_ClearAll()
{
  Plot_ClearAll(MLP_TimePlot);
}

/*!
 * @brief Clears the named series from the plot
 * 
 * Removes a series by name from the time plot. 
 * \param pchSeriesName Name of the series. 
 * */
static inline void TimePlot_Clear(const char *pchSeriesName)
{
  Plot_Clear(MLP_TimePlot, pchSeriesName);
}

#ifdef	__cplusplus
}
#endif

#endif