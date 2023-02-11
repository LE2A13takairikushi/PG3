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

	workers.emplace_back("�^�J�C", "LE2A");
	workers.emplace_back("�J�^�O�`", "LE2A");
}

void TaskManager::Update()
{
	//�Ǘ����l��������
	openum = 0;

	switch (manageMode)
	{
	case MENU:
		cout << "2�Ń^�X�N�̏ڍו\���Ɉړ�" << endl;
		cout << "3�ŃA�v�����I��" << endl;
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
		cout << "1�őO�̃^�X�N��\��" << endl;
		cout << "2�Ŏ��̃^�X�N��\��" << endl;
		cout << "3�œ��e���X�V" << endl;
		cout << "4�Ń^�X�N�����ɒǉ�" << endl;
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
			cout << "���e����͂��Ă�������" << endl;
			cin >> nowTask->contents;
		}

		if (openum == 4)
		{
			//�S���҂�id����͂��Ă�������
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
		cout << "�^�X�N" << endl;
		cout << "�薼:";
		cout << nowTask->taskName << endl;

		cout << "�S����:";
		cout << nowTask->contact.classname + nowTask->contact.name << endl;

		cout << "���e:";
		cout << nowTask->contents << endl;

		cout << "����:";
		cout << nowTask->deadLine << endl;

		cout << "�D��x:";
		switch (nowTask->priority)
		{
		case HIGH:
			cout << "��" << endl;
			break;
		case NORMAL:
			cout << "��" << endl;
			break;
		case LOW:
			cout << "��" << endl;
			break;
		}

		cout << "�X�e�[�^�X:";
		switch (nowTask->status)
		{
		case COMPLETED:
			cout << "����" << endl;
			break;
		case WORKING:
			cout << "��ƒ�" << endl;
			break;
		case NOTSTARTED:
			cout << "������" << endl;
			break;
		}

		cout << endl;
	}
}
