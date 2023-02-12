#pragma once
#include <string>

class Worker
{
public:
	Worker(
		std::string name = "",
		std::string classname = "");

	//担当者のID
	int id;

	//担当者の氏名
	std::string name;

	//担当者のクラス
	std::string classname;

	std::string fName;

	void OutPut();
};

enum PRIORITY_
{
	HIGH,
	NORMAL,
	LOW,
};

enum STATUS_
{
	COMPLETED,
	WORKING,
	NOTSTARTED,
};

class Task
{
public:
	//タスクのID
	int id;

	//タスクの担当者
	Worker contact;

	//タスクの題名
	std::string taskName;

	//タスクの内容
	std::string contents;

	//タスクの優先度(enumで指定する感じにしたいね)
	int priority = LOW;

	//タスクの期限
	std::string deadLine;

	//タスクの状態(完了or作業中or未完了)(enumで指定する感じにしたいね)
	int status = NOTSTARTED;

	std::string fName;

	void OutPut();
};
