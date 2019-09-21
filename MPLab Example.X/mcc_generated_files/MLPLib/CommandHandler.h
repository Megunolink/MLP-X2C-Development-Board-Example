/**
  Command Handler
	
  Company:
    Microchip Technology Inc.

  File Name:
    CommandHandler.h

  Summary:
    Command Handler buffers serial data, detects and processes commands

  Description:
    This is the generated header file for the Command Handler driver.

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

/* 
 * Commands start with a '!' character and are terminated with a '\\r'. Commands
 * may be followed by parameters (separated by spaces). An example command is:
 * @code
 * !SetThreshold 12\r\n
 * @endcode
 * 
 * You'll need a context to hold all the data for the command handler:
 * @code
 * TCommandHandlerContext Commands;
 * @endcode
 * 
 * Initialize and register commands in your setup function:
 * @code
 * void Setup()
 * {
 *   CH_Init(&Commands);
 *   CH_AddCommand(&Commands, "SetThreshold", Cmd_SetThreshold);
 * }
 * @endcode
 * 
 * Functions that process commands must take a TParameters parameter:
 * @code
 * void Cmd_SetThreshold(TParameters *p)
 * {
 *   int nNewThreshold = CH_NextParameterAsInteger(p, 10);
 * }
 * @endcode
 * 
 * Be sure to call the process function in your main loop to buffer serial 
 * characters and dispatch commands as they are detected:
 * @code
 * void Loop()
 * {
 *   CH_Process(&Commands);
 * }
 * @endcode
 */

#ifndef COMMANDHANDLER_H
#define	COMMANDHANDLER_H

/*!
 * @brief Serial buffer size
 * 
 * Size of the buffer allocated for accumulating serial characters until a 
 * complete command is received.
 * */
#ifndef CH_BUFFERSIZE 
#define CH_BUFFERSIZE 30
#endif

/*!
 * @brief The maximum number of commands supported
 * 
 * Space is allocated for a dispatch table for each command. 
 * */
#ifndef CH_MAXCOMMANDS
#define CH_MAXCOMMANDS 10
#endif



#include <stdint.h>
#include "utility\CommandParameters.h"

#ifdef	__cplusplus
extern "C"
{
#endif

/*!
 * @brief The callback function for dispatching commands.
 * */
typedef void (*TCallback)(TParameters*);

/// @cond DEV
/*! 
 * Stores command <-> callback binding. */
typedef struct Command
{
  const char * m_pchCommand;

  TCallback m_fnCallback;

} TCommand;
/// @endcond

/*!
 * @brief Data store for the command handler
 * 
 * Holds the data required for the command handler to operate including 
 * a buffer for characters received and the list of commands we can 
 * process. Treat as opaque.
 * */
typedef struct CommandHandlerContext
{
  /// @cond DEV
  /*! buffer for serial characters */
  char m_achBuffer[CH_BUFFERSIZE];
  
  /*! index into m_achBuffer where the next character goes
   * -1 if we've received too many characters and the buffer has overflowed. */
  uint8_t m_nNextCharacter; // or -1 if overflow. 
  
  /*! Character that marks the start of a new message */
  char m_chStartOfMessage;
  
  /*! character which marks the end of a message. */
  char m_chEndOfMessage;
  
  /*! Number of commands we have to dispatch. */
  uint8_t m_uCommandCount; 
  
  /*! Stores the command bindings we can dispatch. */
  TCommand m_Commands[CH_MAXCOMMANDS];
  
  /// @endcond
  
} TCommandHandlerContext;

/*!
 * @brief Initialize the command handler data
 * 
 * Initializes the command handler context. The context must be initialized 
 * before it can be used.
 * \param pContext Context to be initialized.
 * */
void CH_Init(TCommandHandlerContext *pContext);

/*!
 * @brief Registers a command function binding
 * 
 * Add a new command to the context and binds it to a callback. When the 
 * command is detected by CH_Process, the callback function will be invoked.
 * \param pContext Command handler context. 
 * \param pchCommand The command to match. Must not include spaces. 
 * \param fnCallback The callback function to invoke when the command is received. 
 * */
void CH_AddCommand(TCommandHandlerContext *pContext, const char * pchCommand, TCallback fnCallback);

/*!
 * @brief Process serial characters and dispatch commands
 * 
 * Read characters from the serial stream, detect and dispatch commands
 * as they are encountered. 
 * \param pContext Command handler context.
 * */
void CH_Process(TCommandHandlerContext *pContext);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMANDHANDLER_H */

