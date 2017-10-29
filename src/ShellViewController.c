/*
 * ShellVIewController.c
 *
 *  Created on: Oct 28, 2017
 *      Author: root
 */
#include "ShellViewController.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int deallocateMatrices(int**, int**);

ShellViewController_t* new_ShellViewController(void)
{
	ShellViewController_t* shellViewController = NULL;

	shellViewController = (ShellViewController_t*) malloc ( sizeof( ShellViewController_t ) );
	if ( shellViewController == NULL )
	{
		return NULL;
	}

	shellViewController->shellView = new_ShellView();
	if ( shellViewController->shellView == NULL )
	{
		return NULL;
	}

	shellViewController->shellCommandManager = new_ShellCommandManager();
	if ( shellViewController->shellCommandManager == NULL )
	{
		return NULL;
	}

	shellViewController->matrixCalculator = new_MatrixCalculator();
	if ( shellViewController->matrixCalculator == NULL )
	{
		return NULL;
	}

	shellViewController->control = ShellViewController_Control;

	return shellViewController;
}

void delete_ShellViewController(ShellViewController_t* const shellViewControllerObj)
{
	if ( shellViewControllerObj != NULL )
	{
		delete_MatrixCalculator( shellViewControllerObj->matrixCalculator );
		delete_ShellCommandManager( shellViewControllerObj->shellCommandManager );
		delete_ShellView( shellViewControllerObj->shellView );

		free ( shellViewControllerObj );
	}
}

int ShellViewController_Control(ShellViewController_t* this, ShellData_t* shellData, const char* dataToDisplay)
{
	if ( this == NULL ||
		 shellData == NULL ||
		 dataToDisplay == NULL
		)
	{
		return -1;
	}

	int *inputMatrixOne[MATRIX_MAX_SIZE];
	int *inputMatrixTwo[MATRIX_MAX_SIZE];
	int outputMatrix[MATRIX_MAX_SIZE];
	int matrixRetVal;

	// Check input
	switch ( this->shellCommandManager->manage(this->shellCommandManager, shellData, (const char*) dataToDisplay) )
	{
		case SHELL_COMMAND_DEFAULT_DISPLAY:
			this->shellView->display(this->shellView, shellData, "");
			break;
		case SHELL_COMMAND_USER_CURRENT_WORKING_DIR:
			this->shellView->displayUserInput(this->shellView, shellData->userCurrentWorkingDirectory);
			break;
		case SHELL_COMMAND_SUM_MAX:

			for ( int i = 0; i < MATRIX_MAX_SIZE; ++i)
			{
				inputMatrixOne[i] = (int*) malloc (MATRIX_MAX_SIZE * sizeof(int) );
				inputMatrixTwo[i] = (int*) malloc (MATRIX_MAX_SIZE * sizeof(int) );
			}

			matrixRetVal = this->matrixCalculator->calculate(this->matrixCalculator, inputMatrixOne, inputMatrixTwo, outputMatrix);

			matrixRetVal = this->shellView->displayTwoDimMatrix(this->shellView, inputMatrixOne, MATRIX_MAX_SIZE, MATRIX_MAX_SIZE);
			if (matrixRetVal != 0)
			{
				deallocateMatrices(inputMatrixOne, inputMatrixTwo);
				return -1;
			}

			matrixRetVal = this->shellView->displayTwoDimMatrix(this->shellView, inputMatrixTwo, MATRIX_MAX_SIZE, MATRIX_MAX_SIZE);
			if (matrixRetVal != 0)
			{
				deallocateMatrices(inputMatrixOne, inputMatrixTwo);
				return -1;
			}

			matrixRetVal = this->shellView->displayOneDimMatrix(this->shellView, outputMatrix, MATRIX_MAX_SIZE);
			if (matrixRetVal != 0)
			{
				deallocateMatrices(inputMatrixOne, inputMatrixTwo);
				return -1;
			}

			deallocateMatrices(inputMatrixOne, inputMatrixTwo);

			break;
		case SHEll_COMMAND_CLEAR_SCREEN:
			this->shellView->clearScreen(this->shellView);
			break;
		case SHELL_UNRECOGNIZED_COMMAND:
			this->shellView->displayUserInput(this->shellView, "Unrecognized command");
			return SHELL_VIEW_UNRECOGNIZED_COMMAND;
		case SHELL_COMMAND_EXIT:
			return SHELL_VIEW_EXIT;

		default:
			break;
	}

	return 0;
}

int deallocateMatrices(int** inputMatrixOne, int** inputMatrixTwo)
{
	if ( inputMatrixOne == NULL || *inputMatrixOne == NULL )
	{
		return -1;
	}

	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i)
	{
		free ( inputMatrixOne[i] );
	}

	if ( inputMatrixTwo == NULL || *inputMatrixTwo == NULL  )
	{
		return -1;
	}

	for ( int i = 0; i < MATRIX_MAX_SIZE; ++i)
	{
		free ( inputMatrixTwo[i] );
	}

	return 0;
}
