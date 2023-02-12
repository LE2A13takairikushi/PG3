#include <stdio.h>
#include "TaskManager.h"

int main()
{

	TaskManager taskManager;

	taskManager.Initialize();

	while (true)
	{
		taskManager.Draw();

		taskManager.Update();

		if (taskManager.manageMode == APPEND)break;
	}

	return 0;
}