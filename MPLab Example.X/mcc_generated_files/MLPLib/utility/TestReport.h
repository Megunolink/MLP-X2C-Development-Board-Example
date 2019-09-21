/**
  Test Report
	
  Company:
    Microchip Technology Inc.

  File Name:
    TestReport.h

  Summary:
    Test Report sends data to a MegunoLink test report.  

  Description:
    This is the generated header file for the Test Report driver.

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

#ifndef TESTREPORT_H
#define	TESTREPORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
  
  /*!
   * @brief Report a test result to a test panel
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. */
  void Test_ReportResult(int nTestId, bool bPass);
  
   /*!
   * @brief Report a test result to a test panel with character data
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * Additional test data is shown in the Value column of the test report.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. 
   * \param pchData Null terminated value to show next to the test result.
   * */
  void Test_ReportResult_String(int nTestId, bool bPass, const char *pchData);
  
   /*!
   * @brief Report a test result to a test panel with integer data
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * Additional test data is shown in the Value column of the test report.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. 
   * \param Data Value to show next to the test result.
   * */
  void Test_ReportResult_Int(int nTestId, bool bPass, int Data);
  
   /*!
   * @brief Report a test result to a test panel with unsigned data
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * Additional test data is shown in the Value column of the test report.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. 
   * \param Data Value to show next to the test result.
   * */
  void Test_ReportResult_Unsigned(int nTestId, bool bPass, unsigned Data);
  
   /*!
   * @brief Report a test result to a test panel with long data
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * Additional test data is shown in the Value column of the test report.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. 
   * \param Data Value to show next to the test result.
   * */
  void Test_ReportResult_Long(int nTestId, bool bPass, long Data);
  
   /*!
   * @brief Report a test result to a test panel with unsigned long data
   * 
   * Reports a pass/fail test result to a test panel on a Programmer Visualizer. 
   * The result will be shown in the TestResult column.
   * Additional test data is shown in the Value column of the test report.
   * \param nTestId Id of the test
   * \param bPass True if the test passed; false if it failed. 
   * \param Data Value to show next to the test result.
   * */
  void Test_ReportResult_Unsigned_Long(int nTestId, bool bPass, unsigned long Data);

#ifdef	__cplusplus
}
#endif

#endif	/* TESTREPORT_H */

