#include <stdio.h>
#include "TaskManager.h"



int main()
{

	TaskManager taskManager;
	taskManager.NewTask(takai,"hogehogeTask","仕事しろ","2/28",HIGH,NOTSTARTED);
	taskManager.NewTask(takai, "hogehoge2Task", "仕事しろ", "2/28", LOW, COMPLETED);
	taskManager.NewTask(kataguti, "hogehoge3Task", "仕事しろ", "2/28", HIGH, NOTSTARTED);
	
	taskManager.Initialize();

	while (true)
	{
		taskManager.Draw();

		taskManager.Update();

		if (taskManager.manageMode == APPEND)break;
	}

	return 0;
}