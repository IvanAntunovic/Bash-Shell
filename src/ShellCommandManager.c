#include "ShellCommandManager.h"
#include <string.h>
#include <stdlib.h>

static const char* USER_CURRENT_WORKING_DIR_COMMAND = "pwd";
static const char* SUM_MAX_COMMAND = "sum-max";
static const char* EXIT_COMMAND = "exit";
static const char* CLEAR_SCREEN_COMMAND = "clear";

ShellCommandManager_t* new_ShellCommandManager(void)
{
	ShellCommandManager_t* shellCommandManager = NULL;

	shellCommandManager = (ShellCommandManager_t*) malloc ( sizeof( ShellCommandManager_t ) );
	if ( shellCommandManager == NULL )
	{
		return shellCommandManager;
	}

	shellCommandManager->manage = ShellCommandManager_Manage;

	return shellCommandManager;
}

void delete_ShellCommandManager(ShellCommandManager_t* const shellCommandManagerObj)
{
	if ( shellCommandManagerObj != NULL )
	{
		free ( shellCommandManagerObj );
	}
}

int ShellCommandManager_Manage(ShellCommandManager_t* this, ShellData_t* shellData, const char* command)
{
	if ( this == NULL ||
		 shellData == NULL ||
		 command == NULL
		)
	{
		return -1;
	}

	if ( strcmp(USER_CURRENT_WORKING_DIR_COMMAND, command) == 0 )
	{
		return SHELL_COMMAND_USER_CURRENT_WORKING_DIR;
	}

	if ( strcmp(SUM_MAX_COMMAND, command) == 0 )
	{
		return SHELL_COMMAND_SUM_MAX;
	}

	if ( strcmp(EXIT_COMMAND, command) == 0 )
	{
		return SHELL_COMMAND_EXIT;
	}

	if ( strcmp(CLEAR_SCREEN_COMMAND, command) == 0 )
	{
		return SHEll_COMMAND_CLEAR_SCREEN;
	}

	return SHELL_UNRECOGNIZED_COMMAND;
}
