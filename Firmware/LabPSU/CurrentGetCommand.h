/*
* CurrentGetCommand.h
*
* Created: 21/07/2015 1:10:31 AM
* Author: tom
*/


#ifndef __CURRENT_GET_COMMAND_H__
#define __CURRENT_GET_COMMAND_H__

#include "Command.h"
#include "LabPSU.h"

/*
The current get command is used to read back the current being 
supplied by the PSU.
*/
class CurrentGetCommand : public Command
{
public:

	CurrentGetCommand(LabPSU *psu);
	
	virtual void handleSetCommand( const char *params );
	
	virtual void handleGetCommand() const;
};

#endif //__CURRENT_GET_COMMAND_H__
