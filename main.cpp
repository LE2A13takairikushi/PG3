#include <stdio.h>
#include "TaskManager.h"



int main()
{
	TaskManager taskManager;
	taskManager.NewTask("hogehogeTask");

	taskManager.Draw();

	return 0;
}