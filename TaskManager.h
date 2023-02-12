#pragma once
#include "Task.h"
#include <list>
#include <string>

// DETAILVIEW - �ڍו\�� �^�X�N�̏ڍׂȏ���\������s
// TASKMANAGE - �^�X�N�̒ǉ��A�폜�A�X�e�[�^�X�ύX�A���e�X�V

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

	//�^�X�N�̕`��
	void Draw();

public:
	//�ǂݍ��񂾃^�X�N�̔z��
	std::list<Task> tasks;

	//�ǂݍ��񂾒S���҂̔z��
	std::list<Worker> workers;

	//�A�v���̃V�[�����Ǘ�����enum
	int manageMode = MENU;

private:
	void LoadTask();
	void LoadWorker();

	//���l�ŃR�}���h���Ǘ����邽�߂̐��l
	int openum = 0;
	//���ݕ\�����Ă���^�X�N
	std::list<Task>::iterator nowTask;
};

