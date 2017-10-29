//============================================================================
// Name        : Application.c
// Author      : Ivan Antunovic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "ShellDataManager.h"
#include "ShellViewController.h"
#include <string.h>
#include <stdio.h>

int main()
{
	ShellDataManager_t* shellDataManager = new_ShellManager();
	ShellData_t* shellData = new_ShellData("", "", "", "");
	ShellViewController_t* shellViewController = new_ShellViewController();
	char consoleInput[1024];

	if ( shellDataManager == NULL ||
		 shellData == NULL ||
		 shellViewController == NULL )
	{
		fprintf(stderr, "Null ptr, exiting the application ...");
		return -1;
	}

	if ( shellDataManager->manage(shellDataManager, shellData) != SHELL_DATA_MANAGER_OK )
	{
		fprintf(stderr, "Error while instantiating Shell Manager, exiting the application ...");
		return -1;
	}

	int retVal;

	do
	{
		shellViewController->control(shellViewController, shellData, SHELL_VIEW_CONTROLLER_DEFAULT_DISPLAY);
		scanf("%s", consoleInput);
		retVal = shellViewController->control(shellViewController, shellData, consoleInput);

	}
	while ( retVal != SHELL_VIEW_EXIT );

	delete_ShellDataManager(shellDataManager);
	delete_ShellData(shellData);
	delete_ShellViewController(shellViewController);

	return 0;
}
