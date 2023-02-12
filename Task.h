#pragma once
#include <string>

class Worker
{
public:
	Worker(
		std::string name = "",
		std::string classname = "");

	//�S���҂�ID
	int id;

	//�S���҂̎���
	std::string name;

	//�S���҂̃N���X
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
	//�^�X�N��ID
	int id;

	//�^�X�N�̒S����
	Worker contact;

	//�^�X�N�̑薼
	std::string taskName;

	//�^�X�N�̓��e
	std::string contents;

	//�^�X�N�̗D��x(enum�Ŏw�肷�銴���ɂ�������)
	int priority = LOW;

	//�^�X�N�̊���
	std::string deadLine;

	//�^�X�N�̏��(����or��ƒ�or������)(enum�Ŏw�肷�銴���ɂ�������)
	int status = NOTSTARTED;

	std::string fName;

	void OutPut();
};
