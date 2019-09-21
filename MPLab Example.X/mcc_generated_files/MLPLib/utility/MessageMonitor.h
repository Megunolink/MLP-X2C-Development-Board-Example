/**
  Message Monitor
	
  Company:
    Microchip Technology Inc.

  File Name:
    MessageMonitor.h

  Summary:
    Message Monitor sends data to a MegunoLink message monitor. 

  Description:
    This is the generated header file for the Message Monitor driver.

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


#ifndef MESSAGEMONITOR_H
#define	MESSAGEMONITOR_H

#include "MegunoLinkProtocol.h"
#include <stdbool.h>

/*!
 * @brief Mark the beginning of a message monitor text stream. 
 * 
 * Starts sending text to a Message Monitor visualizer. To stop sending text
 * to the Message Monitor use @ref Message_End().
 * */
void Message_Begin();

/*!
 * @brief Mark the beginning of a message monitor text stream 
 * 
 * Starts sending text to a Message Monitor visualizer. The content can be
 * optionally displayed as text or spoken by the system's built-in speech
 * synthesizer. 
 * 
 * To stop sending text to the Message Monitor use @ref Message_End().
 * 
 * \param bText If True, the message content will be displayed in the 
 * Message Monitor's text window. 
 * \param bSpeak If true, the message content will be spoken by the system's
 * built-in speech synthesizer.
 * */
void Message_BeginEx(bool bText, bool bSpeak);

/*!
 * @brief Send a character string. 
 * 
 * Sends a character string. The string will be displayed/ spoken in a 
 * Message Monitor visualiser if @ref Message_Begin() is called before this 
 * function. 
 * */
static inline void Message_Send_String(const char *pchMessage)
{
  MLP_Print_String(pchMessage);
}

/*!
 * @brief Send an integer value
 * 
 * Sends a integer value. The value will be displayed/ spoken in a 
 * Message Monitor visualiser if @ref Message_Begin() is called before this 
 * function. 
 * */
static inline void Message_Send_Int(int nValue)
{
  MLP_Print_Int(nValue);
}

/*!
 * @brief Send an unsigned value
 * 
 * Sends a unsigned value. The value will be displayed/ spoken in a 
 * Message Monitor visualiser if @ref Message_Begin() is called before this 
 * function. 
 * */
static inline void Message_Send_Unsigned(unsigned uValue)
{
  MLP_Print_UInt(uValue);
}

/*!
 * @brief Send an unsigned long value
 * 
 * Sends a unsigned long value. The value will be displayed/ spoken in a 
 * Message Monitor visualiser if @ref Message_Begin() is called before this 
 * function. 
 * */
static inline void Message_Send_Unsigned_Long(unsigned long ulValue)
{
  MLP_Print_ULong(ulValue);
}

/*!
 * @brief Send an long value
 * 
 * Sends a long value. The value will be displayed/ spoken in a 
 * Message Monitor visualiser if @ref Message_Begin() is called before this 
 * function. 
 * */
static inline void Message_Send_Long(long nlValue)
{
  MLP_Print_Long(nlValue);
}

/*!
 * @brief Send an array of integer values separated by commas
 * 
 * Send an array of integer values separated by commas. The values will be 
 * displayed/ spoken in a  Message Monitor visualiser if 
 * @ref Message_Begin() is called before this function. 
 * */
void Message_Send_CSV_Int(int *pValues, int nValues);

/*!
 * @brief Send an array of integer values separated by commas
 * 
 * Send an array of integer values separated by commas. The values will be 
 * displayed/ spoken in a  Message Monitor visualiser if 
 * @ref Message_Begin() is called before this function. 
 * */
void Message_Send_CSV_Unsigned(unsigned *pValues, int nValues);

/*!
 * @brief Mark the end of text to send to a Message Monitor.
 * 
 * Marks the end of a channel of text for the Message Monitor. The channel is
 * started using @ref Message_Begin() or @ref Message_BeginEx() */
void Message_End();

#endif	/* MESSAGEMONITOR_H */

