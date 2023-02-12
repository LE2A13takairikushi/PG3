#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

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
	tasks.back().fName = "task";
	ostringstream oss;
	oss << tasks.back().id;
	tasks.back().fName += oss.str();
	tasks.back().fName += ".txt";

	//担当者データを空データで挿入
	tasks.back().contact.classname = "";
	tasks.back().contact.name = "";
	tasks.back().contact.id = -1;

	//担当者がいれば担当者の情報を入力
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

	tasks.back().OutPut();
}

void TaskManager::NewWorler(std::string name, std::string classname)
{
	workers.emplace_back(name, classname);
	workers.back().id = workers.size();
	//idに空きがある場合はそっちに優先して入れる
	for (int id = 0; id < workers.size(); id++)
	{
		bool success = true;
		id++;
		for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
		{
			if (itr->id == id)
			{
				success = false;
				break;
			}
		}
		if (success)
		{
			workers.back().id = id;
		}
	}

	workers.back().fName = "worker";
	ostringstream oss;
	oss << workers.back().id;
	workers.back().fName += oss.str();
	workers.back().fName += ".txt";

	workers.back().OutPut();
}

void TaskManager::Initialize()
{
	LoadTask();

	//タスクを先頭に配置
	nowTask = tasks.begin();

	//ここもファイルから読み込みすべき
	LoadWorker();
}

void TaskManager::Update()
{
	//管理数値を初期化
	openum = 0;

	if (manageMode == 0)
	{
		cout << "1で担当者の管理に移動" << endl;
		cout << "2でタスクの詳細表示に移動" << endl;
		cout << "3でアプリを終了" << endl;
		cin >> openum;

		if (openum == 1)
		{
			manageMode = TASKMANAGE;
		}
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
		cout << "1で担当者の新規作成" << endl;
		cout << "2で担当者情報の更新" << endl;
		cout << "3で担当者の削除" << endl;
		cout << "4でメニューに戻る" << endl;
		cin >> openum;
		
		if (openum == 1)
		{
			string name;
			cout << "担当者の名前を入力してください" << endl;
			cin >> name;

			string classname;
			cout << "担当者のクラスを入力してください" << endl;
			cin >> classname;

			NewWorler(name, classname);
			cout << "担当者の新規作成が完了しました" << endl;
		}
		if (openum == 2)
		{
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "変更する担当者のIDを入力してください" << endl;
				cin >> workerID;
				for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
				{
					if (itr->id == workerID)
					{
						clear = false;

						string name;
						cout << "担当者の名前を入力してください" << endl;
						cin >> name;
						itr->name = name;

						string classname;
						cout << "担当者のクラスを入力してください" << endl;
						cin >> classname;
						itr->classname = classname;

						cout << "担当者の情報を更新しました" << endl;

						break;
					}
				}
				if (clear)
				{
					cout << "担当者が見つかりませんでした" << endl;
					cout << "もう一度入力してください" << endl;
				}
			}
		}
		if (openum == 3)
		{
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "削除する担当者のIDを入力してください" << endl;
				cin >> workerID;
				for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
				{
					if (itr->id == workerID)
					{
						workers.erase(itr);
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
			cout << "担当者を削除しました" << endl;
		}
		if (openum == 4)
		{
			manageMode = MENU;
		}
	}
	else if (manageMode == DETAILVIEW)
	{
		cout << "1で前のタスクを表示" << endl;
		cout << "2で次のタスクを表示" << endl;
		cout << "3で内容を更新" << endl;
		cout << "4でタスクを末尾に追加" << endl;
		cout << "5でタスクのステータスを変更" << endl;
		cout << "6でこのタスクを削除" << endl;
		cout << "7でメニューに戻る" << endl;
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
			nowTask->OutPut();
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
		if (openum == 5)
		{
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
			nowTask->priority = priorityT;
			nowTask->OutPut();
		}
		if (openum == 6)
		{
			for (list<Task>::iterator itr = tasks.begin(); itr != tasks.end(); ++itr)
			{
				if (itr == nowTask)
				{
					nowTask--;
					tasks.erase(itr);
					break;
				}
			}
		}
		if (openum == 7)
		{
			manageMode = MENU;
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
		cout << "現在登録されている担当者" << endl;
		for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
		{
			cout << "ID:";
			cout << itr->id << endl;
			cout << "クラス、氏名:"+itr->classname + itr->name << endl;
		}
	}
	if (manageMode == DETAILVIEW)
	{

		cout << "タスク" << endl;
		cout << "題名:";
		cout << nowTask->taskName << endl;

		cout << "担当者:";
		for (list<Task>::iterator itr = tasks.begin(); itr != tasks.end(); ++itr)
		{
			for (list<Worker>::iterator itr2 = workers.begin(); itr2 != workers.end(); ++itr2)
			{
				if (itr->contact.id == itr2->id)
				{
					itr->contact.classname = itr2->classname;
					itr->contact.name = itr2->name;
				}
			}
		}
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

void TaskManager::LoadTask()
{
	//ここで読み込み
	std::ifstream ifs;
	string filename;

	int backNum = 0;
	//エラー吐いたら
	while (1)
	{
		backNum++;
		ostringstream oss;
		oss << backNum;

		filename = "./data/task/task";
		filename += oss.str();
		filename += ".txt";
		ifs.open(filename);

		if (ifs.fail())
		{
			//std::cout << "読み込めないファイルまで到達しました。" << std::endl;

			filename = "task";
			filename += oss.str();
			filename += ".txt";

			//std::cout << "到達ファイル:" << filename << std::endl;
			break;
		}

		tasks.emplace_back();
		string line;
		while (getline(ifs, line))
		{
			std::istringstream line_stream(line);
			//半角スペース区切りで行の先頭文字列を取得
			string key;
			getline(line_stream, key, ' ');

			//先頭のタブ文字は無視する
			if (key[0] == '\t') {
				key.erase(key.begin());//先頭の文字を削除
			}

			//先頭文字列でそれぞれのデータに挿入
			if (key == "taskName") {
				line_stream >> tasks.back().taskName;
			}
			if (key == "contactID") {
				line_stream >> tasks.back().contact.id;
			}
			if (key == "className") {
				line_stream >> tasks.back().contact.classname;
			}
			if (key == "contactName") {
				line_stream >> tasks.back().contact.name;
			}
			if (key == "deadLine") {
				line_stream >> tasks.back().deadLine;
			}
			if (key == "contents") {
				line_stream >> tasks.back().contents;
			}
			if (key == "id") {
				line_stream >> tasks.back().id;
			}
			if (key == "priority") {
				line_stream >> tasks.back().priority;
			}
			if (key == "status") {
				line_stream >> tasks.back().status;
			}
		}
		//ファイルを閉じる
		ifs.close();
	}
}

void TaskManager::LoadWorker()
{
	//ここで読み込み
	std::ifstream ifs;
	string filename;

	int backNum = 0;
	//エラー吐いたら
	while (1)
	{
		backNum++;
		ostringstream oss;
		oss << backNum;

		filename = "./data/worker/worker";
		filename += oss.str();
		filename += ".txt";
		ifs.open(filename);

		if (ifs.fail())
		{
			//std::cout << "読み込めないファイルまで到達しました。" << std::endl;

			filename = "worker";
			filename += oss.str();
			filename += ".txt";

			//std::cout << "到達ファイル:" << filename << std::endl;
			break;
		}

		workers.emplace_back();
		string line;
		while (getline(ifs, line))
		{
			std::istringstream line_stream(line);
			//半角スペース区切りで行の先頭文字列を取得
			string key;
			getline(line_stream, key, ' ');

			//先頭のタブ文字は無視する
			if (key[0] == '\t') {
				key.erase(key.begin());//先頭の文字を削除
			}

			//先頭文字列でそれぞれのデータに挿入
			if (key == "name") {
				line_stream >> workers.back().name;
			}
			if (key == "classname") {
				line_stream >> workers.back().classname;
			}
			if (key == "id") {
				line_stream >> workers.back().id;
			}
		}
		//ファイルを閉じる
		ifs.close();
	}
}
