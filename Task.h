#pragma once
#include <string>

class Worker
{
public:
	//�S���҂�ID
	int id;

	//�S���҂̎���
	std::string name;

	//�S���҂̃N���X
	std::string classname;
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

	//�^�X�N�̗D��x
	std::string priority;

	//�^�X�N�̊���
	std::string deadLine;

	//�^�X�N�̏��(����or��ƒ�or������)
	std::string status;

};
