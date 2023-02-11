#pragma once
#include <string>

class Worker
{
public:
	//担当者のID
	int id;

	//担当者の氏名
	std::string name;

	//担当者のクラス
	std::string classname;
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

	//タスクの優先度
	std::string priority;

	//タスクの期限
	std::string deadLine;

	//タスクの状態(完了or作業中or未完了)
	std::string status;

};
