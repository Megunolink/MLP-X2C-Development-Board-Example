/**
  Table
	
  Company:
    Microchip Technology Inc.

  File Name:
    Table.h

  Summary:
    Table sends data to a MegunoLink table visualizer.  

  Description:
    This is the generated header file for the Table driver.

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

#ifndef _TABLE_H
#define _TABLE_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma once
#include <stdlib.h>

/*!
 * @brief Send an integer value to a MegunoLink table visualizer
 * 
 * Sends a value to a MegunoLink table visualizer. The value is displayed on one 
 * row of the table. If a row with the name already exists, it is updated with 
 * the new value. 
 * \param pchRowName Name of the table row
 * \param Value Value to send
 * */
void Table_Send_Int(const char *pchRowName, int Value);

/*!
 * @brief Send an unsigned integer value to a MegunoLink table visualizer
 * 
 * Sends a value to a MegunoLink table visualizer. The value is displayed on one 
 * row of the table. If a row with the name already exists, it is updated with 
 * the new value. 
 * \param pchRowName Name of the table row
 * \param Value Value to send
 * */
void Table_Send_Unsigned(const char *pchRowName, unsigned Value);

/*!
 * @brief Send an string to a MegunoLink table visualizer
 * 
 * Sends a value to a MegunoLink table visualizer. The value is displayed on one 
 * row of the table. If a row with the name already exists, it is updated with 
 * the new value. 
 * \param pchRowName Name of the table row
 * \param Value Null terminated string to send
 * */
void Table_Send_String(const char *pchRowName, const char *Value);

/*!
 * @brief Displays the current time in a MegunoLink table visualizer
 * 
 * Displays the local time in a row of a MegunoLink table visualizer. Often used 
 * at the start of a program to keep an eye on any unexpected resets. 
 * \param pchRowName Name of the table row to show the time. 
 * */
void Table_ShowCurrentTime(const char *pchRowName);

/*!
 * @brief Sets the description for a table row
 * 
 * Updates the description column for a row in a MegunoLink table visualizer. If 
 * the row doesn't already exist, it is created. 
 * \param pchRowName Name of the table row
 * \param Description Description to send
 * */
void Table_SetDescription(const char *pchRowName, const char *Description);

/*!
 * @brief Clears all rows in the table.
 * */
void Table_ClearAllRows();

/*!
 * @brief Remove a table row by name
 * 
 * Removes the named table row from a MegunoLink table visualizer. 
 * \param pchRowName Name of the table row to remove
 * */
void Table_ClearRow(const char *pchRowName);

/*!
 * @brief Retrieve the value from a table row. 
 * 
 * Replies with the current value from a table row in the form: 
 * {TABLE|RowName|Value}
 * where RowName is replaced by the name of the row and Value is replaced by the 
 * value on that row. No reply is sent if the named row isn't present. 
 * \param pchRowName Name of the table row
 * */
void Table_GetData(const char *pchRowName);

#endif