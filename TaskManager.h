#pragma once
#include "Task.h"
#include <list>
#include <string>

class TaskManager
{
public:
	void NewTask(std::string taskName = "");

	void Draw();

public:
	std::list<Task> tasks;
};

