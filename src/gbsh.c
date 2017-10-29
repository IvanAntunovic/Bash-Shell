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
#include <stdlib.h>
#include <pthread.h>

void* run(void*);

ShellDataManager_t* shellDataManager;
ShellData_t* shellData;
ShellViewController_t* shellViewController;

int main(int argc, char* argv[])
{
	fprintf(stdout, "Hello World!\n");

	int retVal;
	pthread_t shellThread;

	shellDataManager = new_ShellManager();
	shellData = new_ShellData("", "", "", "");
	shellViewController = new_ShellViewController();

	if ( shellDataManager == NULL ||
		 shellData == NULL ||
		 shellViewController == NULL )
	{
		fprintf(stderr, "Null pointer encountered, exiting the application ...");
		exit(-1);
	}

	if ( shellDataManager->manage(shellDataManager, shellData) != SHELL_DATA_MANAGER_OK )
	{
		fprintf(stderr, "Error while instantiating Shell Manager, exiting the application ...");
		exit(-1);
	}

	retVal = pthread_create(&shellThread, NULL, run, (void*) "Shell Thread");
	if ( retVal != 0 )
	{
		fprintf(stderr, "Error while creating the thread, exiting the application ...");
		exit(-1);
	}

	retVal = pthread_join(shellThread, NULL);
	if ( retVal != 0 )
	{
		fprintf(stderr, "Error while creating the thread, exiting the application ...");
		exit(-1);
	}

	delete_ShellDataManager(shellDataManager);
	delete_ShellData(shellData);
	delete_ShellViewController(shellViewController);

	exit(0);
}

void* run(void* parameter)
{
	int retVal;
	char consoleInput[1024];

	do
	{
		shellViewController->control(shellViewController, shellData, SHELL_VIEW_CONTROLLER_DEFAULT_DISPLAY);
		fgets(consoleInput, sizeof(consoleInput), stdin);
		retVal = shellViewController->control(shellViewController, shellData, consoleInput);
	}
	while ( retVal != SHELL_VIEW_EXIT );

	return NULL;
}
