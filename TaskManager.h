#pragma once
#include "Task.h"
#include <list>
#include <string>

// DETAILVIEW - �ڍו\�� �^�X�N�̏ڍׂȏ���\������s
// TASKMANAGE - �^�X�N�̒ǉ��A�폜�A�X�e�[�^�X�ύX�A���e�X�V

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

