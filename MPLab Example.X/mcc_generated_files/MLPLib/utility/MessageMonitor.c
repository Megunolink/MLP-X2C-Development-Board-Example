/**
  Message Monitor
	
  Company:
    Microchip Technology Inc.

  File Name:
    MessageMonitor.c

  Summary:
    Message Monitor sends data to a MegunoLink message monitor. 

  Description:
    This is the generated source file for the Message Monitor driver.

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

#include "MessageMonitor.h"


void Message_Begin()
{
  Message_BeginEx(true, false);
}

void Message_BeginEx(bool bText, bool bSpeak)
{
  if (bText && bSpeak)
  {
    MLP_SendDataHeader(MLP_MessageMonitor, NULL, "SPEAK+DATA");
  }
  else if (bText)
  {
    MLP_SendDataHeader(MLP_MessageMonitor, NULL, "DATA");
  }
  else
  {
    MLP_SendDataHeader(MLP_MessageMonitor, NULL, "SPEAK");
  }
}

void Message_Send_CSV_Int(int *pValues, int nValues)
{
  while(nValues--)
  {
    MLP_Print_Int(*pValues++);
    if (nValues > 0)
    {
      MLP_Print_Char(',');
    }
  }
}

void Message_Send_CSV_Unsigned(unsigned *pValues, int nValues)
{
  while(nValues--)
  {
    MLP_Print_UInt(*pValues++);
    if (nValues > 0)
    {
      MLP_Print_Char(',');
    }
  }
}

void Message_End()
{
  MLP_SendTail();
}