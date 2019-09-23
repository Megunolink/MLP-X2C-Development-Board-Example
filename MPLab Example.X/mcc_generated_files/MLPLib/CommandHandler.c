/**
  Command Handler
	
  Company:
    Microchip Technology Inc.

  File Name:
    CommandHandler.c

  Summary:
    Command Handler buffers serial data, detects and processes commands

  Description:
    This is the generated source file for the Command Handler driver.

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

#include "CommandHandler.h"
#include "utility/MegunoLinkProtocol.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define NO_MATCH 0

void DispatchMessage(TCommandHandlerContext *pContext);
uint8_t MatchCommand(const char * const pchCommand, const char *pchTest);

void CH_Init(TCommandHandlerContext *pContext)
{
  memset(pContext, 0, sizeof (struct CommandHandlerContext));
  pContext->m_nNextCharacter = 0;
  pContext->m_chStartOfMessage = '!';
  pContext->m_chEndOfMessage = '\r';
}

void CH_Process(TCommandHandlerContext *pContext)
{
  int nNextCharacter;
  

  while ((nNextCharacter = MLP_TryReadCharacter()) > 0)
  {
  //printf("test");      
    if (nNextCharacter == pContext->m_chStartOfMessage)
    {
      pContext->m_achBuffer[0] = nNextCharacter;
      pContext->m_nNextCharacter = 1;
    }
    else if (nNextCharacter == pContext->m_chEndOfMessage)
    {
      if (pContext->m_nNextCharacter > 0 && pContext->m_achBuffer[0] == pContext->m_chStartOfMessage)
      {
        pContext->m_achBuffer[pContext->m_nNextCharacter] = '\0';
        DispatchMessage(pContext);
        pContext->m_nNextCharacter = 0;
      }
    }
    else
    {
      if (pContext->m_nNextCharacter >= 0)
      {
        pContext->m_achBuffer[pContext->m_nNextCharacter++] = nNextCharacter;
        if (pContext->m_nNextCharacter >= sizeof (pContext->m_achBuffer))
        {
          pContext->m_nNextCharacter = -1; // Overflow. 
          printf("CMD HDLR OVFL");
        }
      }
    }
  }
}

void CH_AddCommand(TCommandHandlerContext *pContext, const char * pchCommand, TCallback fnCallback)
{
  if (pContext->m_uCommandCount < CH_MAXCOMMANDS)
  {
    pContext->m_Commands[pContext->m_uCommandCount].m_pchCommand = pchCommand;
    pContext->m_Commands[pContext->m_uCommandCount].m_fnCallback = fnCallback;
    ++pContext->m_uCommandCount;
  }
  else
  {
    MLP_Print_String("Too many commands");
  }
}

void DispatchMessage(TCommandHandlerContext *pContext)
{
  //printf("Dispatching: ");
  //printf(pContext->m_achBuffer);

  // Match a command. 
  TCommand *pCommand = pContext->m_Commands;
  uint8_t iCommand;

  for (iCommand = 0; iCommand < pContext->m_uCommandCount; ++iCommand)
  { 
    uint8_t uParameterStart = MatchCommand(pCommand->m_pchCommand, pContext->m_achBuffer + 1);
    if (uParameterStart != NO_MATCH)
    {
      TParameters Parameters;
      Parameters.m_pchNextParameter = pContext->m_achBuffer + uParameterStart;
      (*pCommand->m_fnCallback)(&Parameters);
      return;
    }

    ++pCommand;
  }

  MLP_Print_String("Unknown command");
}

uint8_t MatchCommand(const char * const pchCommand, const char *pchTest)
{
  char chCommand, chTest;
  uint8_t uParameterStart = 0;
  const char * pchTestCmd = pchCommand;

  //printf("Testing: %s\n", pchTestCmd);

  do
  {
    chCommand = *pchTestCmd++;
    chTest = *pchTest++;
    ++uParameterStart;
  }
  while (chCommand == chTest && chCommand != '\0' && (chTest != ' ' || chTest != '\0'));

  if (chCommand == '\0' && (chTest == ' ' || chTest == '\0'))
    return uParameterStart + 1;

  return NO_MATCH;
}

