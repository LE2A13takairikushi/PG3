#include "TaskManager.h"
#include <iostream>

using namespace std;

void TaskManager::NewTask(
	Worker contact,
	std::string taskName,
	std::string contents,
	std::string deadLine,
	int priority,
	int status)
{
	tasks.emplace_back();
	tasks.back().taskName = taskName;
	tasks.back().contents = contents;
	tasks.back().deadLine = deadLine;
	tasks.back().priority = priority;
	tasks.back().status = status;
	tasks.back().id = tasks.size();

	tasks.back().contact.classname = contact.classname;
	tasks.back().contact.name = contact.name;
	tasks.back().contact.id = contact.id;
}

void TaskManager::Initialize()
{
	nowTask = tasks.begin();

	workers.emplace_back("タカイ", "LE2A");
	workers.emplace_back("カタグチ", "LE2A");
}

void TaskManager::Update()
{
	//管理数値を初期化
	openum = 0;

	switch (manageMode)
	{
	case MENU:
		cout << "2でタスクの詳細表示に移動" << endl;
		cout << "3でアプリを終了" << endl;
		cin >> openum;

		if (openum == 2)
		{
			manageMode = DETAILVIEW;
		}
		if (openum == 3)
		{
			manageMode = APPEND;
		}
		break;
	case TASKMANAGE:
	
		break;
	case DETAILVIEW:
		cout << "1で前のタスクを表示" << endl;
		cout << "2で次のタスクを表示" << endl;
		cout << "3で内容を更新" << endl;
		cout << "4でタスクを一つ先に追加" << endl;
		cin >> openum;

		if (openum == 1)
		{
			nowTask--;
		}

		if (openum == 2)
		{
			nowTask++;
		}

		if (openum == 3)
		{
			cout << "内容を入力してください" << endl;
			cin >> nowTask->contents;
		}

		if (openum == 4)
		{
			//担当者のidを入力してください
			int workerID = 0;
			cin >> workerID;

			/*for ()
			{

			}

			NewTask();*/
		}
		break;
	}
}

void TaskManager::Draw()
{
	if (manageMode == MENU)
	{
	}
	if (manageMode == TASKMANAGE)
	{
	}
	if (manageMode == DETAILVIEW)
	{
		cout << "タスク" << endl;
		cout << "題名:";
		cout << nowTask->taskName << endl;

		cout << "担当者:";
		cout << nowTask->contact.classname + nowTask->contact.name << endl;

		cout << "内容:";
		cout << nowTask->contents << endl;

		cout << "期限:";
		cout << nowTask->deadLine << endl;

		cout << "優先度:";
		switch (nowTask->priority)
		{
		case HIGH:
			cout << "高" << endl;
			break;
		case NORMAL:
			cout << "中" << endl;
			break;
		case LOW:
			cout << "低" << endl;
			break;
		}

		cout << "ステータス:";
		switch (nowTask->status)
		{
		case COMPLETED:
			cout << "完了" << endl;
			break;
		case WORKING:
			cout << "作業中" << endl;
			break;
		case NOTSTARTED:
			cout << "未完了" << endl;
			break;
		}

		cout << endl;
	}
}
