/*
 * ShellVIewController.h
 *
 *  Created on: Oct 28, 2017
 *      Author: root
 */

#ifndef SRC_SHELLVIEWCONTROLLER_H_
#define SRC_SHELLVIEWCONTROLLER_H_

#include "ShellView.h"
#include "ShellCommandManager.h"
#include "MatrixCalculator.h"

#define SHELL_VIEW_CONTROLLER_DEFAULT_DISPLAY "DEFAULT_DISPLAY"
#define SHELL_VIEW_EXIT -2

typedef struct ShellViewController ShellViewController_t;

// declaration of pointers to functions
typedef int (*funcPtrControl_t)(ShellViewController_t*, ShellData_t*, const char* dataToDisplay);

typedef struct ShellViewController
{
	ShellView_t* shellView;
	ShellCommandManager_t* shellCommandManager;
	MatrixCalculator_t* matrixCalculator;
	funcPtrControl_t control;

} ShellViewController_t;

ShellViewController_t* new_ShellViewController(void);
void delete_ShellViewController(ShellViewController_t* const shellViewControllerObj);
int ShellViewController_Control(ShellViewController_t* this, ShellData_t* shellData, const char* dataToDisplay);

#endif /* SRC_SHELLVIEW_H_ */
