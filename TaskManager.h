#pragma once
#include "Task.h"
#include <list>
#include <string>

// DETAILVIEW - 詳細表示 タスクの詳細な情報を表示するs
// TASKMANAGE - タスクの追加、削除、ステータス変更、内容更新

enum MANAGEMODE
{
	MENU,
	TASKMANAGE,
	DETAILVIEW,
	APPEND,
};

class TaskManager
{
public:
	void NewTask(
		int workerID,
		std::string taskName, 
		std::string contents,
		std::string deadLine,
		int priority,
		int status);

	void NewWorler(std::string name = "",
		std::string classname = "");

	void Initialize();

	void Update();

	void Draw();

public:
	std::list<Task> tasks;
	std::list<Worker> workers;

	int manageMode = MENU;

private:

	int openum = 0;

	std::list<Task>::iterator nowTask;
};

