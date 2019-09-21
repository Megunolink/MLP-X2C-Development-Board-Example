/**
  XY Plot
	
  Company:
    Microchip Technology Inc.

  File Name:
    XYPlot.h

  Summary:
    XY Plot sends data to a MegunoLink X-Y Plot visualizer.   

  Description:
    This is the generated header file for the XY Plot driver.

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

#ifndef XYPLOT_H
#define	XYPLOT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "MegunoLinkProtocol.h"
#include "Plot_impl.h"

/*!
 * @brief Send an integer value to a MegunoLink X-Y Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink X-Y Plot visualizer.  
 * \param pchSeriesName Name of the table row
 * \param nX x-value for plot (horizontal axis)
 * \param nY y-value for plot (vertical axis)
 * */
void XYPlot_Send_Int(const char *pchSeriesName, int nX, int nY);

/*!
 * @brief Send an long integer value to a MegunoLink X-Y Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink X-Y Plot visualizer.  
 * \param pchSeriesName Name of the table row
 * \param lX x-value for plot (horizontal axis)
 * \param lY y-value for plot (vertical axis)
 * */
void XYPlot_Send_Long(const char *pchSeriesName, long lX, long lY);

/*!
 * @brief Send a double value to a MegunoLink X-Y Plot visualizer
 * 
 * Sends a value to a series on a MegunoLink X-Y Plot visualizer.  
 * \param pchSeriesName Name of the table row
 * \param lX x-value for plot (horizontal axis)
 * \param lY y-value for plot (vertical axis)
 * */
void XYPlot_Send_Double(const char *pchSeriesName, double lX, double lY);

/*!
 * @brief Sets the plot title
 * 
 * Sets the time title of an x-y plot. 
 * \param pchTitle The new title of the plot (null terminated string). 
 * */
static inline void XYPlot_SetTitle(const char *pchTitle)
{
  Plot_SetTitle(MLP_XYPlot, pchTitle);
}

/*!
 * @brief Set the label for the x-axis 
 * \param pchLabel A null terminated string label for the plot's x-axis
 * (horizontal axis). 
 * */
static inline void XYPlot_SetXLabel(const char *pchLabel)
{
  Plot_SetXLabel(MLP_XYPlot, pchLabel);
}

/*!
 * @brief Set the label for the y-axis
 * \param pchLabel A null terminated string label for the plot's y-axis
 * (vertical axis). 
 * */
static inline void XYPlot_SetYLabel(const char *pchLabel)
{
  Plot_SetYLabel(MLP_XYPlot, pchLabel);
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
static inline void XYPlot_SetSeriesProperties(const char *pchSeriesName, enum Colors Color, enum LineStyle Line, unsigned uLineWidth, enum MarkerStyle Marker)
{
  Plot_SetSeriesProperties(MLP_XYPlot, pchSeriesName, Color, Line, uLineWidth, Marker);
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
static inline void XYPlot_SetSeriesProperties_String(const char *pchSeriesName, const char *pchSeriesProperties)
{
  Plot_SetSeriesProperties_String(MLP_XYPlot, pchSeriesName, pchSeriesProperties);
}

/*!
 * @brief Clears all series from the x-y plot
 * */
static inline void XYPlot_ClearAll()
{
  Plot_ClearAll(MLP_XYPlot);
}

/*!
 * @brief Clears the named series from the plot
 * 
 * Removes a series by name from the x-y plot.
 * \param pchSeriesName Name of the series. 
 * */
static inline void XYPlot_Clear(const char *pchSeriesName)
{
  Plot_Clear(MLP_XYPlot, pchSeriesName);
}




#ifdef	__cplusplus
}
#endif

#endif	/* XYPLOT_H */

