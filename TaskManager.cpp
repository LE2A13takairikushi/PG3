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

	NewWorler("�^�J�C", "LE2A");
	NewWorler("�J�^�O�`", "LE2A");
}

void TaskManager::Update()
{
	//�Ǘ����l��������
	openum = 0;

	if (manageMode == MENU)
	{
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
	}
	else if (manageMode == TASKMANAGE)
	{

	}
	else if (manageMode == DETAILVIEW)
	{
		cout << "1�őO�̃^�X�N��\��" << endl;
		cout << "2�Ŏ��̃^�X�N��\��" << endl;
		cout << "3�œ��e���X�V" << endl;
		cout << "4�Ń^�X�N�𖖔��ɒǉ�" << endl;
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
			cout << "���e����͂��Ă�������" << endl;
			cin >> nowTask->contents;
		}

		if (openum == 4)
		{
			//�S���҂�ID�����
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "�S���҂�ID����͂��Ă�������" << endl;
				cin >> workerID;
				for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
				{
					if (itr->id == workerID)
					{
						cout << "�S����:" + itr->classname + itr->name << endl;
						clear = false;
						break;
					}
				}
				if (clear)
				{
					cout << "�S���҂�������܂���ł���" << endl;
					cout << "������x���͂��Ă�������" << endl;
				}
			}

			//�^�X�N�̑薼�����
			string taskNameT;
			cout << "�^�X�N�̑薼����͂��Ă�������" << endl;
			cin >> taskNameT;

			//�^�X�N�̑薼�����
			string contentsT;
			cout << "���e����͂��Ă�������" << endl;
			cin >> contentsT;

			//�^�X�N�̊��������
			string deadLineT;
			cout << "��������͂��Ă�������" << endl;
			cin >> deadLineT;

			//�^�X�N�̗D��x�����
			int priorityT = -1;
			while (priorityT == -1)
			{
				priorityT = 0;
				cout << "�D��x����͂��Ă�������" << endl;
				cout << "1�ō�" << endl;
				cout << "2�Œ�" << endl;
				cout << "3�Œ�" << endl;
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
				//�͈͊O�̏ꍇ�̏�������肭�����˂��I�I
				if (priorityT == -1)
				{
					cout << "�w�肳�ꂽ�͈͂ł͂���܂���" << endl;
					cout << "������x���͂��Ă�������" << endl;
				}
				else
				{
					break;
				}
			}

			//�^�X�N�̏�Ԃ����
			int statusT;
			statusT = NOTSTARTED;

			NewTask(workerID, taskNameT, contentsT, deadLineT, priorityT, statusT);
			nowTask = tasks.end();
			nowTask--;

			cout << "�^�X�N�̒ǉ����������܂���" << endl;
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
