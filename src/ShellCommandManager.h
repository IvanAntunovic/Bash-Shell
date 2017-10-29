/*
 * ShellCommandManager.h
 *
 *  Created on: Oct 28, 2017
 *      Author: root
 */

#ifndef SRC_SHELLCOMMANDMANAGER_H_
#define SRC_SHELLCOMMANDMANAGER_H_

#include "ShellData.h"

#define SHELL_COMMAND_USER_CURRENT_WORKING_DIR 1
#define SHELL_COMMAND_EXIT 2
#define SHELL_COMMAND_SUM_MAX 3
#define SHEll_COMMAND_CLEAR_SCREEN 4
#define SHELL_UNRECOGNIZED_COMMAND 5

typedef struct ShellCommandManager ShellCommandManager_t;

// declaration of pointers to functions
typedef int (*funcPtrManage_t)(ShellCommandManager_t* this, ShellData_t* shellData, const char* command);

typedef struct ShellCommandManager
{
	funcPtrManage_t manage;

} ShellCommandManager_t;

ShellCommandManager_t* new_ShellCommandManager(void);
void delete_ShellCommandManager(ShellCommandManager_t* const shellCommandManagerObj);
int ShellCommandManager_Manage(ShellCommandManager_t* this, ShellData_t* shellData, const char* command);

#endif /* SRC_SHELLCOMMANDMANAGER_H_ */
