/* 
* CommandFactory.cpp
*
* Created: 21/07/2015 11:17:00 PM
* Author: tom
*/


#include "CommandFactory.h"
#include "string.h"
#include "stdio.h"

CommandFactory::CommandFactory( LabPSU *psu ) 
    :	m_voltageSetCommand(psu), 
        m_currentSetCommand(psu), 
        m_voltageGetCommand(psu),
        m_currentGetCommand(psu),
        m_outputEnableCommand(psu),
        m_inCurrentLimitCommand(psu),
        m_voltageDACCommand(psu),
        m_voltageADCCommand(psu),
        m_currentDACCommand(psu),
        m_currentADCCommand(psu),
		m_voltageADCCalCommand(psu),
		m_voltageDACCalCommand(psu),
		m_currentADCCalCommand(psu),
		m_currentDACCalCommand(psu)
{
    for(int i=0;i<MAX_COMMANDS;i++)
    {
        m_commandArray[i] = NULL;
    }
            
    addCommand(&m_voltageSetCommand);
    addCommand(&m_currentSetCommand);
    addCommand(&m_voltageGetCommand);
    addCommand(&m_currentGetCommand);
    addCommand(&m_outputEnableCommand);
    addCommand(&m_inCurrentLimitCommand);
    addCommand(&m_voltageDACCommand);
    addCommand(&m_voltageADCCommand);
    addCommand(&m_currentDACCommand);
    addCommand(&m_currentADCCommand);
	addCommand(&m_voltageADCCalCommand);
	addCommand(&m_voltageDACCalCommand);
	addCommand(&m_currentADCCalCommand);
	addCommand(&m_currentDACCalCommand);
}

Command *CommandFactory::getCommand( const char *commandName ) const
{
    for(int i=0;i<MAX_COMMANDS;i++)
    {
        Command *nextCommand = m_commandArray[i];
        
        if ( nextCommand == NULL )
        {
            return NULL;
        }
        
        if ( nextCommand->handlesThis(commandName))
        {
            return nextCommand;
        }
    }	
    
    return NULL;
}

void CommandFactory::addCommand( Command *command )
{
    for(int i=0;i<MAX_COMMANDS;i++)
    {
        if ( m_commandArray[i] == NULL )
        {
            m_commandArray[i] = command;
            return;
        }
    }
    
    printf("Failed to initialize command array - array too small");
}
