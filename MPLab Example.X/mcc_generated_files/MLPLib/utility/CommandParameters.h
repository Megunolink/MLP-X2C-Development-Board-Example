/**
  Command Parameters
	
  Company:
    Microchip Technology Inc.

  File Name:
    CommandParameters.h

  Summary:
    Command Parameters includes functions for extracting parameters from command strings. 

  Description:
    This is the generated header file for the Command Parameters driver.

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

#ifndef COMMANDPARAMETERS_H
#define	COMMANDPARAMETERS_H

#ifdef	__cplusplus
extern "C"
{
#endif


/*!
 * @brief Holds parameter data for dispatching commands
 * */
typedef struct Parameters
{
  /// @cond DEV
  /*! 
   * Points to the first character of the next parameter. 
   * Points to '\0' if the end of the parameter string. */
  char *m_pchNextParameter; 
  /// @endcond
} TParameters;

/*!
 * Retrieve the next parameter supplied with the command. Parameters are separated
 * by spaces. 
 * \param pParameterBlock Pointer to the parameter block data
 * \return A pointer to the null terminated parameter. Points to a null if there
 * are no more parameters
 * */
const char *CH_NextParameter(TParameters *pParameterBlock );

/*!
 * Retrieve the next command parameter, converting it to an integer. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param nDefault Default value
 * \return Next command parameter interpreted as an integer, or the default
 * value if that isn't possible. 
 * */
int CH_NextParameterAsInteger(TParameters *pParameterBlock, int nDefault);

/*!
 * Retrieve the next command parameter, converting it to an long. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param lDefault Default value
 * \return Next command parameter interpreted as an long, or the default
 * value if that isn't possible. 
 * */
long CH_NextParameterAsLong(TParameters *pParameterBlock, long lDefault);

/*!
 * Retrieve the next command parameter, converting it to an unsigned. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param uDefault Default value
 * \return Next command parameter interpreted as an unsigned, or the default
 * value if that isn't possible. 
 * */
unsigned CH_NextParameterAsUnsignedInteger(TParameters *pParameterBlock, unsigned uDefault);

/*!
 * Retrieve the next command parameter, converting it to an unsigned long. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param ulDefault Default value
 * \return Next command parameter interpreted as an unsigned long, or the default
 * value if that isn't possible. 
 * */
unsigned long CH_NextParameterAsUnsignedLong(TParameters *pParameterBlock, unsigned long ulDefault);

/*!
 * Retrieve the next command parameter, converting it to an long long. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param llDefault Default value
 * \return Next command parameter interpreted as an long long, or the default
 * value if that isn't possible. 
 * */
long long CH_NextParametersAsLongLong(TParameters *pParameterBlock, long long llDefault);

/*!
 * Retrieve the next command parameter, converting it to an unsigned long long. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param ullDefault Default value
 * \return Next command parameter interpreted as an unsigned long long, or the default
 * value if that isn't possible. 
 * */
unsigned long long CH_NextParametersAsUnsignedLongLong(TParameters *pParameterBlock, unsigned long long ullDefault);

/*!
 * Retrieve the next command parameter, converting it to an double. Returns a
 * default value if the parameter is missing or invalid. 
 * \param pParameterBlock Pointer to the parameter block data
 * \param dDefault Default value
 * \return Next command parameter interpreted as an double, or the default
 * value if that isn't possible. 
 * */
double CH_NextParameterAsDouble(TParameters *pParameterBlock, double dDefault);

#ifdef	__cplusplus
}
#endif

#endif	/* COMMANDPARAMETERS_H */

