#include <stdio.h>
#include "TaskManager.h"



int main()
{

	TaskManager taskManager;
	taskManager.NewTask(0,"hogehogeTask","仕事しろ","2/28",HIGH,NOTSTARTED);
	taskManager.NewTask(0, "hogehoge2Task", "仕事しろ", "2/28", LOW, COMPLETED);
	taskManager.NewTask(1, "hogehoge3Task", "仕事しろ", "2/28", HIGH, NOTSTARTED);
	
	taskManager.Initialize();

	while (true)
	{
		taskManager.Draw();

		taskManager.Update();

		if (taskManager.manageMode == APPEND)break;
	}

	return 0;
}