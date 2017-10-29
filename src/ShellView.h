/*
 * ShellView.h
 *
 *  Created on: Oct 28, 2017
 *      Author: root
 */

#ifndef SRC_SHELLVIEW_H_
#define SRC_SHELLVIEW_H_

#include "ShellData.h"

typedef struct ShellView ShellView_t;

// declaration of pointers to functions
typedef int (*funcPtrDisplay_t)(ShellView_t*, ShellData_t*, const char* dataToDisplay);
typedef int (*displayUserInput_t)(ShellView_t*, const char* dataToDisplay);
typedef int (*displayOneDimMatrix_t)(ShellView_t*, int* matrixToDisplay, int rowSize);
typedef int (*displayTwoDimMatrix_t)(ShellView_t*, int** matrixToDisplay, int rowSize, int columnSize);
typedef void (*clearScreen_t)(ShellView_t*);

typedef struct ShellView
{
	funcPtrDisplay_t display;
	displayUserInput_t displayUserInput;
	displayOneDimMatrix_t displayOneDimMatrix;
	displayTwoDimMatrix_t displayTwoDimMatrix;
	clearScreen_t clearScreen;

} ShellView_t;

ShellView_t* new_ShellView(void);
void delete_ShellView(ShellView_t* const shellViewObj);
int ShellView_Display(ShellView_t* this, ShellData_t* shellData, const char* dataToDisplay);
int ShellView_DisplayUserInput(ShellView_t* this, const char* dataToDisplay);
int ShellView_DisplayOneDimMatrix(ShellView_t* this, int* matrixToDisplay, int rowSize);
int ShellView_DisplayTwoDimMatrix(ShellView_t* this, int** matrixToDisplay, int rowSize, int columnSize);
void ShellView_ClearScreen(ShellView_t* this);

#endif /* SRC_SHELLVIEW_H_ */
