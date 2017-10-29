#ifndef _SHELL_MANAGER_H_
#define _SHELL_MANAGER_H_

#include "ShellData.h"

#define SHELL_DATA_MANAGER_OK 0
#define SHELL_DATA_MANAGER_NOK -1
#define SHELL_DATA_MANAGER_NULL_PTR -2

typedef struct ShellDataManager ShellDataManager_t;

// declaration of pointers to functions
typedef int (*funcPtrManager_t)(ShellDataManager_t*, ShellData_t*);

typedef struct ShellDataManager
{
	funcPtrManager_t manage;

} ShellDataManager_t;

ShellDataManager_t* new_ShellManager(void);
void delete_ShellDataManager(ShellDataManager_t* const shellDataManagerObj);
int ShellDataManager_Manage(ShellDataManager_t* this, ShellData_t* shellData);

#endif
