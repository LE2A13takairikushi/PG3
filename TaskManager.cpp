#include "TaskManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

void TaskManager::NewTask(
	int workerID,
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

	while (1)
	{
		for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
		{
			if (itr->id == workerID)
			{
				tasks.back().contact.classname = itr->classname;
				tasks.back().contact.name = itr->name;
				tasks.back().contact.id = itr->id;
				break;
			}
		}

		tasks.back().contact.classname = "";
		tasks.back().contact.name = "";
		tasks.back().contact.id = -1;
		break;
	}
}

void TaskManager::NewWorler(std::string name, std::string classname)
{
	workers.emplace_back(name, classname);
	workers.back().id = workers.size();
}

void TaskManager::Initialize()
{
	nowTask = tasks.begin();

	NewWorler("タカイ", "LE2A");
	NewWorler("カタグチ", "LE2A");
}

void TaskManager::Update()
{
	//管理数値を初期化
	openum = 0;

	if (manageMode == MENU)
	{
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
	}
	else if (manageMode == TASKMANAGE)
	{

	}
	else if (manageMode == DETAILVIEW)
	{
		cout << "1で前のタスクを表示" << endl;
		cout << "2で次のタスクを表示" << endl;
		cout << "3で内容を更新" << endl;
		cout << "4でタスクを末尾に追加" << endl;
		cin >> openum;

		if (openum == 1)
		{
			nowTask--;
		}
		if (openum == 2)
		{
			nowTask++;
			if (nowTask == tasks.end())nowTask--;
		}

		if (openum == 3)
		{
			cout << "内容を入力してください" << endl;
			cin >> nowTask->contents;
		}

		if (openum == 4)
		{
			//担当者のIDを入力
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "担当者のIDを入力してください" << endl;
				cin >> workerID;
				for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
				{
					if (itr->id == workerID)
					{
						cout << "担当者:" + itr->classname + itr->name << endl;
						clear = false;
						break;
					}
				}
				if (clear)
				{
					cout << "担当者が見つかりませんでした" << endl;
					cout << "もう一度入力してください" << endl;
				}
			}

			//タスクの題名を入力
			string taskNameT;
			cout << "タスクの題名を入力してください" << endl;
			cin >> taskNameT;

			//タスクの題名を入力
			string contentsT;
			cout << "内容を入力してください" << endl;
			cin >> contentsT;

			//タスクの期限を入力
			string deadLineT;
			cout << "期限を入力してください" << endl;
			cin >> deadLineT;

			//タスクの優先度を入力
			int priorityT = -1;
			while (priorityT == -1)
			{
				priorityT = 0;
				cout << "優先度を入力してください" << endl;
				cout << "1で高" << endl;
				cout << "2で中" << endl;
				cout << "3で低" << endl;
				cin >> priorityT;
				switch (priorityT)
				{
				case 1:
					priorityT = HIGH;
					break;
				case 2:
					priorityT = NORMAL;
					break;
				case 3:
					priorityT = LOW;
					break;
				default:
					priorityT = -1;
					break;
				}
				//範囲外の場合の処理が上手くいかねえ！！
				if (priorityT == -1)
				{
					cout << "指定された範囲ではありません" << endl;
					cout << "もう一度入力してください" << endl;
				}
				else
				{
					break;
				}
			}

			//タスクの状態を入力
			int statusT;
			statusT = NOTSTARTED;

			NewTask(workerID, taskNameT, contentsT, deadLineT, priorityT, statusT);
			nowTask = tasks.end();
			nowTask--;

			cout << "タスクの追加が完了しました" << endl;
		}
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
