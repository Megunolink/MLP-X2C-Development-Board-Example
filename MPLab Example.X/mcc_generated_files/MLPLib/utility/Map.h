/**
  Map
	
  Company:
    Microchip Technology Inc.

  File Name:
    Map.h

  Summary:
    Map sends data to a MegunoLink Map visualizer.

  Description:
    This is the generated header file for the Map driver.

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

#ifndef MAP_H
#define	MAP_H

#include <stdlib.h>


#ifdef	__cplusplus
extern "C" {
#endif

  /*!
   * @brief Send position to a Map visualizer
   * 
   * Sends a latitude and longitude, in string format, to a map visualizer. 
   * \param pchPlacename Label to use for the location (null terminated string)
   * \param pchLatitude Position latitude as a floating point, null-terminated 
   * character string. 
   * \param pchLongitude Position longitude as a floating point, null-terminated
   * character string. 
   * */
  void Map_Send_String(const char *pchPlacename, const char *pchLatitude, const char *pchLongitude);
  
  
  /*!
   * @brief Send position to a Map visualizer
   * 
   * Sends a latitude and longitude, to a map visualizer. 
   * \param pchPlacename Label to use for the location (null terminated string)
   * \param dLatitude Position latitude as a double-precision number
   * \param dLongitude Position longitude as a double-precision number
   * */
  void Map_Send_Double(const char *pchPlacename, double dLatitude, double dLongitude);


#ifdef	__cplusplus
}
#endif

#endif	/* MAP_H */

