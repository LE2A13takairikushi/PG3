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
	cout << "タスク" << endl;
	cout << "題名" << endl;
	cout << tasks.back().taskName << endl;
	
	cout << "内容" << endl;
	cout << tasks.back().contents << endl;

	cout << "期限" << endl;
	cout << tasks.back().deadLine << endl;

	cout << "優先度" << endl;
	cout << tasks.back().priority << endl;
	
	cout << "ステータス" << endl;
	cout << tasks.back().status << endl;
}
