/**
  Interface Panel
	
  Company:
    Microchip Technology Inc.

  File Name:
    InterfacePanel.c

  Summary:
    Interface Panel update controls on a MegunoLink Interface Panel visualizer.

  Description:
    This is the generated source file for the Interface Panel driver.

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

#include "InterfacePanel.h"
#include "MegunoLinkProtocol.h"

void SendControlHeader(const char *pchControlName, const char *pchPropertyName);
void SendBooleanValue(bool bValue);

void SendControlHeader(const char *pchControlName, const char *pchPropertyName)
{
  MLP_SendDataHeader(MLP_InterfacePanel, NULL, "SET");
  MLP_Print_String(pchControlName);
  MLP_Print_Char('.');
  MLP_Print_String(pchPropertyName);
  MLP_Print_Char('=');
}

void SendBooleanValue(bool bValue)
{
  MLP_Print_String(bValue ? "True" : "False");
}

void IP_SetText_String(const char * ControlName, const char * Value)
{
  SendControlHeader(ControlName, "Text");
  MLP_Print_String(Value);
  MLP_SendTail();
}

void IP_SetText_Int(const char * ControlName, int Value)
{
  SendControlHeader(ControlName, "Text");
  MLP_Print_Int(Value);
  MLP_SendTail();
} 

void IP_SetText_Long(const char * ControlName, long Value)
{
  SendControlHeader(ControlName, "Text");
  MLP_Print_Long(Value);
  MLP_SendTail();
}

void IP_SetText_Unsigned_Long(const char * ControlName, unsigned long Value)
{
  SendControlHeader(ControlName, "Text");
  MLP_Print_ULong(Value);
  MLP_SendTail(); 
}

void IP_SetText_Double(const char * ControlName, double Value)
{
  SendControlHeader(ControlName, "Text");
  MLP_Print_Double(Value);
  MLP_SendTail();   
}

void IP_SetProgress(const char * ControlName, int nValue)
{
  IP_SetNumber_Int(ControlName, nValue);  
}

void IP_SetNumber_Int(const char * ControlName, int Value)
{
  SendControlHeader(ControlName, "Value");
  MLP_Print_Int(Value);
  MLP_SendTail();   
} 

void IP_SetNumber_Long(const char * ControlName, long Value)
{
  SendControlHeader(ControlName, "Value");
  MLP_Print_Long(Value);
  MLP_SendTail();   
} 

void IP_SetNumber_Unsigned_Long(const char * ControlName, unsigned long Value)
{
  SendControlHeader(ControlName, "Value");
  MLP_Print_Long(Value);
  MLP_SendTail();   
}

void IP_SetNumber_Double(const char * ControlName, double Value)
{
  SendControlHeader(ControlName, "Value");
  MLP_Print_Double(Value);
  MLP_SendTail();   
}

void IP_SetListIndex(const char * ControlName, int nIndex)
{
  SendControlHeader(ControlName, "SelectedIndex");
  MLP_Print_Int(nIndex);
  MLP_SendTail();   
}

void IP_SetListValue(const char * ControlName, int nIndex)
{
  IP_SetNumber_Int(ControlName, nIndex);
}

void IP_SetListName(const char * ControlName, const char *ValueName)
{
  SendControlHeader(ControlName, "SelectedName");
  MLP_Print_String(ValueName);
  MLP_SendTail();   
}

void IP_SetCheck(const char * ControlName, bool bChecked)
{
  SendControlHeader(ControlName, "Checked");
  SendBooleanValue(bChecked);
  MLP_SendTail();    
}

void IP_ShowControl(const char * ControlName)
{
  SendControlHeader(ControlName, "Visible");
  SendBooleanValue(true);
  MLP_SendTail();  
}

void IP_HideControl(const char * ControlName)
{
  SendControlHeader(ControlName, "Visible");
  SendBooleanValue(false);
  MLP_SendTail();  
}

void IP_EnableControl(const char * ControlName)
{
  SendControlHeader(ControlName, "Enabled");
  SendBooleanValue(true);
  MLP_SendTail();  
}

void IP_DisableControl(const char * ControlName)
{
  SendControlHeader(ControlName, "Enabled");
  SendBooleanValue(false);
  MLP_SendTail();  
}

void IP_SetForeColor(const char *ControlName, const char *Color)
{
  SendControlHeader(ControlName, "ForeColor");
  MLP_Print_String(Color);
  MLP_SendTail();   
}

void IP_SetBackColor(const char *ControlName, const char *Color)
{
  SendControlHeader(ControlName, "BackColor");
  MLP_Print_String(Color);
  MLP_SendTail();   
}

void IP_CallCommand(const char* CommandName)
{
  MLP_SendDataHeader(MLP_InterfacePanel, NULL, "CMD");
  MLP_Print_String(CommandName);
  MLP_SendTail();  
}

void IP_GetValue(const char* ControlName, const char* PropertyName)
{
  MLP_SendDataHeader(MLP_InterfacePanel, NULL, "GET");
  MLP_Print_String(ControlName);
  MLP_Print_Char('.');
  MLP_Print_String(PropertyName);
  MLP_SendTail();  
}

void IP_SetReadOnly(const char *ControlName, bool ReadOnly)
{
  SendControlHeader(ControlName, "ReadOnly");
  SendBooleanValue(ReadOnly);
  MLP_SendTail();   
}

void IP_SetMinimum(const char *ControlName, int Value)
{
  SendControlHeader(ControlName, "Minimum");
  MLP_Print_Int(Value);
  MLP_SendTail();  
}

void IP_SetMaximum(const char *ControlName, int Value)
{
  SendControlHeader(ControlName, "Maximum");
  MLP_Print_Int(Value);
  MLP_SendTail();  
}

  
