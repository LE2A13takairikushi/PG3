#include "TaskManager.h"
#include <iostream>

using namespace std;

void TaskManager::NewTask(std::string taskName)
{
	tasks.emplace_back();
	tasks.back().taskName = taskName;
	tasks.back().contents = "";
	tasks.back().deadLine = "";
	tasks.back().priority = "";
	tasks.back().status = "";
	tasks.back().id = tasks.size();

	tasks.back().contact.classname = "";
	tasks.back().contact.name = "";
	tasks.back().contact.id;
}

void TaskManager::Draw()
{
	cout << "�^�X�N" << endl;
	cout << "�薼" << endl;
	cout << tasks.back().taskName << endl;
	
	cout << "���e" << endl;
	cout << tasks.back().contents << endl;

	cout << "����" << endl;
	cout << tasks.back().deadLine << endl;

	cout << "�D��x" << endl;
	cout << tasks.back().priority << endl;
	
	cout << "�X�e�[�^�X" << endl;
	cout << tasks.back().status << endl;
}
