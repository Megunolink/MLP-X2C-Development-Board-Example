/**
  Interface Panel
	
  Company:
    Microchip Technology Inc.

  File Name:
    InterfacePanel.h

  Summary:
    Interface Panel update controls on a MegunoLink Interface Panel visualizer.

  Description:
    This is the generated header file for the Interface Panel driver.

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


#ifndef INTERFACEPANEL_H
#define	INTERFACEPANEL_H

#include <stdbool.h>

#ifdef	__cplusplus
extern "C"
{
#endif

  /*!
   * @brief Update control text
   * 
   * Sets the text displayed by a control. 
   * Button: sets the button text
   * TextBox: sets the content of the text-box
   * DynamicLabel: set the label text
   * \param ControlName Name of the control
   * \param Value New value for the control's text
   * */
  void IP_SetText_String(const char * ControlName, const char * Value);
  
  /*!
   * @brief Update control text to a integer value
   * 
   * Sets the text displayed by a control. 
   * Button: sets the button text
   * TextBox: sets the content of the text-box
   * DynamicLabel: set the label text
   * \param ControlName Name of the control
   * \param Value New value for the control's text
   * */
  void IP_SetText_Int(const char * ControlName, int Value);  
  
  /*!
   * @brief Update control text to a long value
   * 
   * Sets the text displayed by a control. 
   * Button: sets the button text
   * TextBox: sets the content of the text-box
   * DynamicLabel: set the label text
   * \param ControlName Name of the control
   * \param Value New value for the control's text
   * */
  void IP_SetText_Long(const char * ControlName, long Value);  
  
  /*!
   * @brief Update control text to an unsigned long value
   * 
   * Sets the text displayed by a control. 
   * Button: sets the button text
   * TextBox: sets the content of the text-box
   * DynamicLabel: set the label text
   * \param ControlName Name of the control
   * \param Value New value for the control's text
   * */
  void IP_SetText_Unsigned_Long(const char * ControlName, unsigned long Value);
  
  /*!
   * @brief Update control text to a double value
   * 
   * Sets the text displayed by a control. 
   * Button: sets the button text
   * TextBox: sets the content of the text-box
   * DynamicLabel: set the label text
   * \param ControlName Name of the control
   * \param Value New value for the control's text
   * */
  void IP_SetText_Double(const char * ControlName, double Value);

  
  /*!
   * @brief Update a progress bar
   * 
   * Sets the position of the progress bar highlight to a value. If the value is 
   * larger or smaller than the maximum range supported by the progress bar it 
   * will be clamped to the allowed range. 
   * 
   * \param ControlName Name of the control
   * \param nValue New progress value
   * */
  void IP_SetProgress(const char * ControlName, int nValue);

  /*!
   * @brief Update a NumericUpDown, TrackBarWithIndicator or Gauge control
   * 
   * Sets the numeric value displayed by a control. If the value is 
   * larger or smaller than the maximum range supported by the control it 
   * will be clamped to the allowed range. 
   * 
   * \param ControlName Name of the control
   * \param Value New value
   * */
  void IP_SetNumber_Int(const char * ControlName, int Value);  

  /*!
   * @brief Update a NumericUpDown, TrackBarWithIndicator or Gauge control
   * 
   * Sets the numeric value displayed by a control. If the value is 
   * larger or smaller than the maximum range supported by the control it 
   * will be clamped to the allowed range. 
   * 
   * \param ControlName Name of the control
   * \param Value New value
   * */
  void IP_SetNumber_Long(const char * ControlName, long Value);  

  /*!
   * @brief Update a NumericUpDown, TrackBarWithIndicator or Gauge control
   * 
   * Sets the numeric value displayed by a control. If the value is 
   * larger or smaller than the maximum range supported by the control it 
   * will be clamped to the allowed range. 
   * 
   * \param ControlName Name of the control
   * \param Value New value
   * */
  void IP_SetNumber_Unsigned_Long(const char * ControlName, unsigned long Value);

  /*!
   * @brief Update a NumericUpDown, TrackBarWithIndicator or Gauge control
   * 
   * Sets the numeric value displayed by a control. If the value is 
   * larger or smaller than the maximum range supported by the control it 
   * will be clamped to the allowed range. 
   * 
   * \param ControlName Name of the control
   * \param Value New value
   * */
  void IP_SetNumber_Double(const char * ControlName, double Value);


  /*!
   * @brief Update the selected item in a ValueList control
   * 
   * Sets the selected item in a ValueList control based on its index. 
   * 
   * \param ControlName Name of the control
   * \param nIndex Index of item to select. The first item is at index 0.
   * */
  void IP_SetListIndex(const char * ControlName, int nIndex);

  /*!
   * @brief Update the selected item in a ValueList control
   * 
   * Sets the selected item(s) in a ValueList control based on a value. In a 
   * single selection list, any item with a matching value will be selected. In
   * a multi-selection list, any item with a value having the same bits set as
   * \p nValue will be selected. That is an item will be selected when 
   * (Item.Value & \p nValue) == Item.Value
   * \param ControlName Name of the control
   * \param nValue Value of items to select.
   * */
  void IP_SetListValue(const char * ControlName, int nValue);

  /*!
   * @brief Update the selected item in a ValueList control
   * 
   * Sets the selected item(s) in a ValueList control based on the name of
   * the value. 
   * 
   * \param ControlName Name of the control
   * \param ValueName Name of item to select.
   * */
  void IP_SetListName(const char * ControlName, const char *ValueName);

  /*!
   * @brief Update the check state of a CheckBox or RadioButton control
   * 
   * Check or uncheck a CheckBox or RadioButton control. When a radio button
   * control is checked, any other controls in the same group will be automatically
   * unchecked. 
   * 
   * \param ControlName Name of the control
   * \param bChecked If true/non-zero, the control will be checked; if false/
   * zero it will be unchecked.
   * */
  void IP_SetCheck(const char * ControlName, bool bChecked);

  /*!
   * @brief Makes a control visible
   * 
   * Makes a control on an Interface Panel visible to the user. 
   * \param ControlName Name of the control to show
   * */
  void IP_ShowControl(const char * ControlName);

  /*!
   * @brief Hides a control
   * 
   * Makes a control on an Interface Panel invisible to the user. 
   * \param ControlName Name of the control to hide
   * */
  void IP_HideControl(const char * ControlName);

  /*!
   * @brief Enables a control
   * 
   * Enables a control so that the user can interact with it. 
   * \param ControlName Name of the control to enable
   * */
  void IP_EnableControl(const char * ControlName);

  /*!
   * @brief Disable a control
   * 
   * Disable a control so that the user can't interact with it. Typically the
   * control appears grayed out 
   * \param ControlName Name of the control to disable
   * */
  void IP_DisableControl(const char * ControlName);

  /*!
   * @brief Set a controls foreground color
   * 
   * Set the foreground color of a control. On buttons, labels and text boxes
   * this is the color used to draw the text. 
   *  
   * \param ControlName Name of the control
   * \param Color New foreground color. Use named colors or a 6 digit hex value
   * of the form RRGGBB. Supported color names are https://msdn.microsoft.com/en-us/library/system.windows.media.colors(v=vs.110).aspx
   * */
  void IP_SetForeColor(const char *ControlName, const char *Color);

  /*!
   * @brief Set a controls background color
   * 
   * Set the background color of a control.  
   *  
   * \param ControlName Name of the control
   * \param Color New background color. Use named colors or a 6 digit hex value
   * of the form RRGGBB. Supported color names are https://msdn.microsoft.com/en-us/library/system.windows.media.colors(v=vs.110).aspx
   * */
  void IP_SetBackColor(const char *ControlName, const char *Color);
  
  /*!
   * @brief Invoke a command from a MessageLibrary
   * 
   * Invokes a command, by name, in a MessageLibrary. Commands typically respond
   * with information from controls on the Interface Panel in a custom format. 
   * \param CommandName Name of the command to invoke. 
   * */
  void IP_CallCommand(const char* CommandName);
  
  /*!
   * @brief Retrieve a control property value
   * 
   * Retrieves the value of the named control property. 
   * \param ControlName Name of the control
   * \param PropertyName Name of the property to retrieve. 
   * */
  void IP_GetValue(const char* ControlName, const char* PropertyName);
  
  /*!
   * @brief Makes a TextBox control read only
   * 
   * Sets a text box control to be read only. The value displayed in a read-only
   * control can be selected and copied by the user but it can't be changed. 
   * 
   * \param ControlName Name of the TextBox to change
   * \param ReadOnly True/false to enable/disable read-only property of the 
   * control.
   * */
  void IP_SetReadOnly(const char *ControlName, bool ReadOnly);
  
  /*!
   * @brief Sets the minimum value of a control
   * 
   * Updates the minimum value for a NumericUpDown, ProgressBar or TrackBarWithIndicator
   * control. If the current control value is below this minimum it is changed
   * to the new minimum value. 
   * 
   * \param ControlName The name of the control
   * \param Value New control minimum 
   * */
  void IP_SetMinimum(const char *ControlName, int Value);
  
  /*!
   * @brief Sets the maximum value of a control
   * 
   * Updates the maximum value for a NumericUpDown, ProgressBar or TrackBarWithIndicator
   * control. If the current control value is above this maximum it is changed
   * to the new maximum value. 
   * 
   * \param ControlName The name of the control
   * \param Value New control minimum 
   * */
  void IP_SetMaximum(const char *ControlName, int Value);

#ifdef	__cplusplus
}
#endif

#endif	/* INTERFACEPANEL_H */

