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

	//�S���҃f�[�^����f�[�^�ő}��
	tasks.back().contact.classname = "";
	tasks.back().contact.name = "";
	tasks.back().contact.id = -1;

	//�S���҂�����ΒS���҂̏������
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
	//id�ɋ󂫂�����ꍇ�͂������ɗD�悵�ē����
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

	//�^�X�N��擪�ɔz�u
	nowTask = tasks.begin();

	//�������t�@�C������ǂݍ��݂��ׂ�
	LoadWorker();
}

void TaskManager::Update()
{
	//�Ǘ����l��������
	openum = 0;

	if (manageMode == 0)
	{
		cout << "1�ŒS���҂̊Ǘ��Ɉړ�" << endl;
		cout << "2�Ń^�X�N�̏ڍו\���Ɉړ�" << endl;
		cout << "3�ŃA�v�����I��" << endl;
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
		cout << "1�ŒS���҂̐V�K�쐬" << endl;
		cout << "2�ŒS���ҏ��̍X�V" << endl;
		cout << "3�ŒS���҂̍폜" << endl;
		cout << "4�Ń��j���[�ɖ߂�" << endl;
		cin >> openum;
		
		if (openum == 1)
		{
			string name;
			cout << "�S���҂̖��O����͂��Ă�������" << endl;
			cin >> name;

			string classname;
			cout << "�S���҂̃N���X����͂��Ă�������" << endl;
			cin >> classname;

			NewWorler(name, classname);
			cout << "�S���҂̐V�K�쐬���������܂���" << endl;
		}
		if (openum == 2)
		{
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "�ύX����S���҂�ID����͂��Ă�������" << endl;
				cin >> workerID;
				for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
				{
					if (itr->id == workerID)
					{
						clear = false;

						string name;
						cout << "�S���҂̖��O����͂��Ă�������" << endl;
						cin >> name;
						itr->name = name;

						string classname;
						cout << "�S���҂̃N���X����͂��Ă�������" << endl;
						cin >> classname;
						itr->classname = classname;

						cout << "�S���҂̏����X�V���܂���" << endl;

						break;
					}
				}
				if (clear)
				{
					cout << "�S���҂�������܂���ł���" << endl;
					cout << "������x���͂��Ă�������" << endl;
				}
			}
		}
		if (openum == 3)
		{
			int workerID = 0;
			bool clear = true;
			while (clear)
			{
				cout << "�폜����S���҂�ID����͂��Ă�������" << endl;
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
					cout << "�S���҂�������܂���ł���" << endl;
					cout << "������x���͂��Ă�������" << endl;
				}
			}
			cout << "�S���҂��폜���܂���" << endl;
		}
		if (openum == 4)
		{
			manageMode = MENU;
		}
	}
	else if (manageMode == DETAILVIEW)
	{
		cout << "1�őO�̃^�X�N��\��" << endl;
		cout << "2�Ŏ��̃^�X�N��\��" << endl;
		cout << "3�œ��e���X�V" << endl;
		cout << "4�Ń^�X�N�𖖔��ɒǉ�" << endl;
		cout << "5�Ń^�X�N�̃X�e�[�^�X��ύX" << endl;
		cout << "6�ł��̃^�X�N���폜" << endl;
		cout << "7�Ń��j���[�ɖ߂�" << endl;
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
			nowTask->OutPut();
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
		if (openum == 5)
		{
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
		cout << "���ݓo�^����Ă���S����" << endl;
		for (list<Worker>::iterator itr = workers.begin(); itr != workers.end(); ++itr)
		{
			cout << "ID:";
			cout << itr->id << endl;
			cout << "�N���X�A����:"+itr->classname + itr->name << endl;
		}
	}
	if (manageMode == DETAILVIEW)
	{

		cout << "�^�X�N" << endl;
		cout << "�薼:";
		cout << nowTask->taskName << endl;

		cout << "�S����:";
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

void TaskManager::LoadTask()
{
	//�����œǂݍ���
	std::ifstream ifs;
	string filename;

	int backNum = 0;
	//�G���[�f������
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
			//std::cout << "�ǂݍ��߂Ȃ��t�@�C���܂œ��B���܂����B" << std::endl;

			filename = "task";
			filename += oss.str();
			filename += ".txt";

			//std::cout << "���B�t�@�C��:" << filename << std::endl;
			break;
		}

		tasks.emplace_back();
		string line;
		while (getline(ifs, line))
		{
			std::istringstream line_stream(line);
			//���p�X�y�[�X��؂�ōs�̐擪��������擾
			string key;
			getline(line_stream, key, ' ');

			//�擪�̃^�u�����͖�������
			if (key[0] == '\t') {
				key.erase(key.begin());//�擪�̕������폜
			}

			//�擪������ł��ꂼ��̃f�[�^�ɑ}��
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
		//�t�@�C�������
		ifs.close();
	}
}

void TaskManager::LoadWorker()
{
	//�����œǂݍ���
	std::ifstream ifs;
	string filename;

	int backNum = 0;
	//�G���[�f������
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
			//std::cout << "�ǂݍ��߂Ȃ��t�@�C���܂œ��B���܂����B" << std::endl;

			filename = "worker";
			filename += oss.str();
			filename += ".txt";

			//std::cout << "���B�t�@�C��:" << filename << std::endl;
			break;
		}

		workers.emplace_back();
		string line;
		while (getline(ifs, line))
		{
			std::istringstream line_stream(line);
			//���p�X�y�[�X��؂�ōs�̐擪��������擾
			string key;
			getline(line_stream, key, ' ');

			//�擪�̃^�u�����͖�������
			if (key[0] == '\t') {
				key.erase(key.begin());//�擪�̕������폜
			}

			//�擪������ł��ꂼ��̃f�[�^�ɑ}��
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
		//�t�@�C�������
		ifs.close();
	}
}
