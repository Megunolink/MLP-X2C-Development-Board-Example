/**
  Command Parameters
	
  Company:
    Microchip Technology Inc.

  File Name:
    CommandParameters.c

  Summary:
    Command Parameters includes functions for extracting parameters from command strings. 

  Description:
    This is the generated source file for the Command Parameters driver.

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

#include <string.h>
#include <limits.h>
#include <stdlib.h>


#include "CommandParameters.h"

const char *CH_NextParameter(TParameters *p) {
    if (*(p->m_pchNextParameter) == '\0')
        return NULL;

    // Null terminate the next parameter
    char *pchParameter = p->m_pchNextParameter;
    char *pchEnd = pchParameter;
    while (*pchEnd != ' ' && *pchEnd != '\0') {
        ++pchEnd;
    }

    if (*pchEnd != '\0') {
        *pchEnd++ = '\0';
    }
    p->m_pchNextParameter = pchEnd;

    return pchParameter;

}

int CH_NextParameterAsInteger(TParameters *p, int nDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return nDefault;

    return atoi(pchParameter);
}

long CH_NextParameterAsLong(TParameters *p, long lDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return lDefault;

    return atol(pchParameter);
}

unsigned CH_NextParameterAsUnsignedInteger(TParameters *p, unsigned uDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return uDefault;

    char *pchEnd;
    unsigned long ulValue = strtoul(pchParameter, &pchEnd, 0);
    return ulValue & ULONG_MAX;
}

unsigned long CH_NextParameterAsUnsignedLong(TParameters *p, unsigned long ulDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return ulDefault;

    char *pchEnd;
    return strtoul(pchParameter, &pchEnd, 0);
}

double CH_NextParameterAsDouble(TParameters *p, double dDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return dDefault;

    return atof(pchParameter);
}

#ifndef __XC8
//Tried #if ULLONG_MAX>=4294967296 but it doesnt seem to work
// XC8 does not support long long types

long long CH_NextParametersAsLongLong(TParameters *p, long long llDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return llDefault;

    return atoll(pchParameter);
}

unsigned long long CH_NextParametersAsUnsignedLongLong(TParameters *p, unsigned long long ullDefault) {
    const char *pchParameter = CH_NextParameter(p);
    if (pchParameter == NULL)
        return ullDefault;

    char *pchEnd;
    return strtoull(pchParameter, &pchEnd, 0);
}
#endif


