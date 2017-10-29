/*
 * ShellView.c

 *
 *  Created on: Oct 28, 2017
 *      Author: Ivan Antunovic
 */
#include "ShellView.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ShellView_t* new_ShellView(void)
{
	ShellView_t* shellView = NULL;

	shellView = (ShellView_t*) malloc ( sizeof( ShellView_t ) );
	if ( shellView == NULL )
	{
		return NULL;
	}

	shellView->display = ShellView_Display;
	shellView->displayUserInput = ShellView_DisplayUserInput;
	shellView->displayOneDimMatrix = ShellView_DisplayOneDimMatrix;
	shellView->displayTwoDimMatrix = ShellView_DisplayTwoDimMatrix;
	shellView->clearScreen = ShellView_ClearScreen;

	return shellView;
}

void delete_ShellView(ShellView_t* const shellViewObj)
{
	if ( shellViewObj != NULL )
	{
		free ( shellViewObj );
	}
}

int ShellView_Display(ShellView_t* this, ShellData_t* shellData, const char* dataToDisplay)
{
	if ( this == NULL ||
		 shellData == NULL ||
		 dataToDisplay == NULL
		)
	{
		return -1;
	}

	printf("<%s>@<%s> <%s> >%s",  shellData->userName, shellData->hostName, shellData->currentWorkingDirectory, dataToDisplay);

	return 0;
}

int ShellView_DisplayUserInput(ShellView_t* this, const char* dataToDisplay)
{
	if ( this == NULL ||
		 dataToDisplay == NULL
		)
	{
		return -1;
	}

	printf("%s\n",  dataToDisplay);

	return 0;
}

int ShellView_DisplayOneDimMatrix(ShellView_t* this, int* matrixToDisplay, int rowSize)
{
	if ( this == NULL || matrixToDisplay == NULL )
	{
		return -1;
	}

	for ( int i = 0; i < rowSize; ++i )
	{
		printf("%d\t", matrixToDisplay[i]);
	}
	printf("%s", "\n");

	return 0;
}


int ShellView_DisplayTwoDimMatrix(ShellView_t* this, int** matrixToDisplay, int rowSize, int columnSize)
{
	if ( this == NULL || matrixToDisplay == NULL || *matrixToDisplay == NULL)
	{
		return -1;
	}

	for ( int i = 0; i < rowSize; ++i )
	{
		for ( int j = 0; j < columnSize; ++j )
		{
			printf("%d\t", matrixToDisplay[i][j]);
		}
		printf("%s", "\n");
	}
	printf("%s", "\n");

	return 0;
}

void ShellView_ClearScreen(ShellView_t* this)
{
	system("@cls||clear");
}




