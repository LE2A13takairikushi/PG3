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

	//タスクの描画
	void Draw();

public:
	//読み込んだタスクの配列
	std::list<Task> tasks;

	//読み込んだ担当者の配列
	std::list<Worker> workers;

	//アプリのシーンを管理するenum
	int manageMode = MENU;

private:
	void LoadTask();
	void LoadWorker();

	//数値でコマンドを管理するための数値
	int openum = 0;
	//現在表示しているタスク
	std::list<Task>::iterator nowTask;
};

