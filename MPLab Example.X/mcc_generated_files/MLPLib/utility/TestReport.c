/**
  Test Report
	
  Company:
    Microchip Technology Inc.

  File Name:
    TestReport.c

  Summary:
    Test Report sends data to a MegunoLink test report.  

  Description:
    This is the generated source file for the Test Report driver.

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

#include "TestReport.h"
#include "MegunoLinkProtocol.h"

void SendFirstPart(bool bPass, int nTestId)
{
  if (bPass)
  {
    MLP_SendDataHeader(MLP_Test, NULL, "PASS");
  }
  else
  {
    MLP_SendDataHeader(MLP_Test, NULL, "FAIL");
  }
  MLP_Print_Int(nTestId);
}

void Test_ReportResult(int nTestId, bool bPass)
{
  SendFirstPart(bPass, nTestId);
  MLP_SendTail();
}

void Test_ReportResult_String(int nTestId, bool bPass, const char *pchData)
{
  SendFirstPart(bPass, nTestId);
  MLP_Print_Separator();
  MLP_Print_String(pchData);
  MLP_SendTail();
}

void Test_ReportResult_Int(int nTestId, bool bPass, int Data)
{
  SendFirstPart(bPass, nTestId);
  MLP_Print_Separator();
  MLP_Print_Int(Data);
  MLP_SendTail();
}

void Test_ReportResult_Unsigned(int nTestId, bool bPass, unsigned Data)
{
  SendFirstPart(bPass, nTestId);
  MLP_Print_Separator();
  MLP_Print_UInt(Data);
  MLP_SendTail();
}

void Test_ReportResult_Long(int nTestId, bool bPass, long Data)
{
  SendFirstPart(bPass, nTestId);
  MLP_Print_Separator();
  MLP_Print_Long(Data);
  MLP_SendTail();
}

void Test_ReportResult_Unsigned_Long(int nTestId, bool bPass, unsigned long Data)
{
  SendFirstPart(bPass, nTestId);
  MLP_Print_Separator();
  MLP_Print_ULong(Data);
  MLP_SendTail();
}
