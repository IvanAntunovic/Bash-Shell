/*
 * ShellDataManager.c

 *
 *  Created on: Oct 27, 2017
 *      Author: root
 */
#include "ShellDataManager.h"
#include <linux/kernel.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

extern char* cuserid(char*);

ShellDataManager_t* new_ShellManager(void)
{
	ShellDataManager_t* shellDataManager = NULL;

	shellDataManager = (ShellDataManager_t*) malloc ( sizeof( ShellDataManager_t) );
	if ( shellDataManager == NULL )
	{
		return shellDataManager;
	}

	shellDataManager->manage = ShellDataManager_Manage;

	return shellDataManager;
}

void delete_ShellDataManager(ShellDataManager_t* const shellDataManagerObj)
{
	if ( shellDataManagerObj != NULL )
	{
		free( shellDataManagerObj );
	}
}

int ShellDataManager_Manage(ShellDataManager_t* this, ShellData_t* shellData)
{
	char currentWorkingDir[1024];

	if ( shellData == NULL )
	{
		return SHELL_DATA_MANAGER_NULL_PTR;
	}

	if ( shellData->userName == NULL ||
		 shellData->currentWorkingDirectory == NULL ||
		 shellData->hostName == NULL	)
	{
		return SHELL_DATA_MANAGER_NULL_PTR;
	}


	if ( getcwd(currentWorkingDir, sizeof(currentWorkingDir)) == NULL )
	{
		return SHELL_DATA_MANAGER_NULL_PTR;
	}

	strcpy(shellData->currentWorkingDirectory, currentWorkingDir);

	if ( gethostname(shellData->hostName, 20) != 0 )
	{
		return SHELL_DATA_MANAGER_NOK;
	}

	if ( cuserid(shellData->userName) == NULL )
	{
		return SHELL_DATA_MANAGER_NULL_PTR;
	}

	struct passwd* pws;
	pws = getpwuid(geteuid());

	strcpy(shellData->userCurrentWorkingDirectory, pws->pw_dir);

	return SHELL_DATA_MANAGER_OK;
}



