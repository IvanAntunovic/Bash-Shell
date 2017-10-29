#ifndef _SHELL_DATA_H_
#define _SHELL_DATA_H_

void ShellData_Show(void);

typedef struct ShellData
{
	char* userName;
	char* currentWorkingDirectory;
	char* userCurrentWorkingDirectory;
	char* hostName;
} ShellData_t;

ShellData_t* new_ShellData(const char* username,
						   const char* currentWorkingDirectory,
						   const char* userCurrentWorkingDirectory,
						   const char* hostName);
void delete_ShellData(ShellData_t* const shellDataObj);

#endif
