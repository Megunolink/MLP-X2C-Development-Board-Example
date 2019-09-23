/**
  Megunolink Protocol
	
  Company:
    Microchip Technology Inc.

  File Name:
    MegunolinkProtocol.c

  Summary:
    Megunolink Protocol

  Description:
    This is the generated source file for the Megunolink Protocol driver.

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

#include "MegunoLinkProtocol.h"
#include "stdio.h"
#include <string.h>
#include "../../mcc.h"


#if !defined(MLP_USE_PRINTF_FORMATTING)
#define MLP_USE_PRINTF_FORMATTING 1
#endif

void WriteContext(enum EContext Context)
{
    const char *pchContext = NULL;
    switch (Context)
    {
    case MLP_Table:
        pchContext = "TABLE";
        break;

    case MLP_TimePlot:
        pchContext = "TIMEPLOT";
        break;

    case MLP_XYPlot:
        pchContext = "XYPLOT";
        break;

    case MLP_MessageMonitor:
        pchContext = "MESSAGE";
        break;

    case MLP_Map:
        pchContext = "MAP";
        break;

    case MLP_InterfacePanel:
        pchContext = "UI";
        break;

    case MLP_Test:
        pchContext = "TEST";
        break;

    }

    if (pchContext != NULL)
    {
        MLP_Print_String(pchContext);
    }
}

void MLP_SendDataHeader(enum EContext Context, const char *pchChannel, const char *pchCommand)
{
    MLP_Print_Char('{');
    WriteContext(Context);
    if (pchChannel != NULL)
    {
        MLP_Print_Char(':');
        MLP_Print_String(pchChannel);
    }
    MLP_Print_Char('|');
    MLP_Print_String(pchCommand);
    MLP_Print_Char('|');
}

void MLP_Print_Int(int nValue)
{
    int nDigit;
    int nRest = nValue;
    int nSign = nValue < 0 ? -1: 1;

    char chBuffer[sizeof (int) * 3 + 2];
    int iDigit = sizeof (chBuffer) - 1;
    chBuffer[iDigit--] = '\0';

    do
    {
        nDigit = (nRest % 10)*nSign;
        chBuffer[iDigit--] = '0' + nDigit;
        nRest /= 10;
    }
    while (nRest);

    if (nValue < 0)
    {
        chBuffer[iDigit--] = '-';
    }

    MLP_Print_String(chBuffer + iDigit + 1);
}

void MLP_Print_UInt(unsigned uValue)
{
    int nDigit;
    unsigned nRest = uValue;
    char chBuffer[sizeof (int) * 3 + 2];
    int iDigit = sizeof (chBuffer) - 1;
    chBuffer[iDigit--] = '\0';

    do
    {
        nDigit = nRest % 10;
        chBuffer[iDigit--] = '0' + nDigit;
        nRest /= 10;
    }
    while (nRest);

    MLP_Print_String(chBuffer + iDigit + 1);
}

void MLP_Print_ULong(unsigned long ulValue)
{
    int nDigit;
    unsigned long nRest = ulValue;
    char chBuffer[sizeof (unsigned long) * 3 + 2];
    int iDigit = sizeof (chBuffer) - 1;
    chBuffer[iDigit--] = '\0';

    do
    {
        nDigit = nRest % 10;
        chBuffer[iDigit--] = '0' + nDigit;
        nRest /= 10;
    }
    while (nRest);


    MLP_Print_String(chBuffer + iDigit + 1);
}

void MLP_Print_Long(long nValue)
{
    int nDigit;
    long nRest = nValue;
    int nSign = nValue < 0 ? -1: 1;

    char chBuffer[sizeof (long) * 3 + 2];
    int iDigit = sizeof (chBuffer) - 1;
    chBuffer[iDigit--] = '\0';

    do
    {
        nDigit = (nRest % 10) * nSign;
        chBuffer[iDigit--] = '0' + nDigit;
        nRest /= 10;
    }
    while (nRest);

    if (nValue < 0)
    {
        chBuffer[iDigit--] = '-';
    }

    MLP_Print_String(chBuffer + iDigit + 1);
}

void MLP_Print_String(const char *pch)
{
  printf(pch);
}

void MLP_Print_Char(char ch)
{
  putchar(ch);
}

void MLP_Print_Separator()
{
  MLP_Print_Char('|');
}

void MLP_SendTail()
{
  MLP_Print_Char('}');
  MLP_Print_Char('\n');
}

void MLP_Print_Double(double dValue)
{
#if defined(MLP_USE_PRINTF_FORMATTING)
    printf("%f", dValue);
#endif
}

int MLP_TryReadCharacter()
{
    if ( EUSART_is_rx_ready() ==0)
    {
        return -1;
    }

    return EUSART_Read();
}
