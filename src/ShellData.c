/*
 * ShellData.c
 *
 *  Created on: Oct 27, 2017
 *      Author: root
 */
#include "ShellData.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

#define BUFFER_MIN_SIZE 1024

ShellData_t* new_ShellData(const char* userName,
						   const char* currentWorkingDirectory,
						   const char* userCurrentWorkingDirectory,
						   const char* hostName)
{
	ShellData_t* shellData = NULL;

	if ( userName == NULL ||
		 currentWorkingDirectory == NULL ||
		 userCurrentWorkingDirectory == NULL ||
		 hostName == NULL	)
	{
		return NULL;
	}

	shellData = (ShellData_t*) malloc ( sizeof( ShellData_t) );
	if ( shellData == NULL )
	{
		return shellData;
	}

	shellData->userName 					= (char*) malloc( BUFFER_MIN_SIZE * sizeof(char) );
	shellData->currentWorkingDirectory 		= (char*) malloc( BUFFER_MIN_SIZE * sizeof(char) );
	shellData->userCurrentWorkingDirectory  = (char*) malloc( BUFFER_MIN_SIZE * sizeof(char) );
	shellData->hostName 					= (char*) malloc( BUFFER_MIN_SIZE * sizeof(char) );

	strcpy(shellData->userName, userName);
	strcpy(shellData->currentWorkingDirectory, currentWorkingDirectory);
	strcpy(shellData->userCurrentWorkingDirectory, userCurrentWorkingDirectory);
	strcpy(shellData->hostName, hostName);

	return shellData;
}

void delete_ShellData(ShellData_t* const shellDataObj)
{
	if ( shellDataObj != NULL )
	{
		if ( shellDataObj->currentWorkingDirectory != NULL )
		{
			free( shellDataObj->currentWorkingDirectory );
		}

		if ( shellDataObj->hostName != NULL )
		{
			free( shellDataObj->hostName );
		}

		if ( shellDataObj->userCurrentWorkingDirectory != NULL )
		{
			free( shellDataObj->userCurrentWorkingDirectory );
		}

		if ( shellDataObj->userName != NULL )
		{
			free( shellDataObj->userName );
		}

		free( shellDataObj );
	}
}




