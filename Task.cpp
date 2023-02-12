#include "Task.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Worker::Worker(std::string name, std::string classname) 
	: name(name),classname(classname)
{

}

void Worker::OutPut()
{
	std::ofstream ofs("./data/worker/" + fName);

	if (ofs.fail()) {
		std::cerr << "Failed to out file." << std::endl;
	}
	ofs << "name " + name << std::endl;
	ofs << "classname " + classname << std::endl;

	ostringstream oss;
	oss << id;
	ofs << "id " + oss.str() << std::endl;
}

void Task::OutPut()
{
	std::ofstream ofs("./data/task/"+fName);

	if (ofs.fail()) {
		std::cerr << "Failed to out file." << std::endl;
	}
	ofs << "taskName " + taskName << std::endl;

	ostringstream oss;
	oss << contact.id;
	ofs << "contactID " + oss.str() << std::endl;

	ofs << "className " + contact.classname << std::endl;
	ofs << "contactName " + contact.name << std::endl;
	ofs << "deadLine " + deadLine << std::endl;
	ofs << "contents " + contents << std::endl;

	ostringstream oss2;
	oss2 << id;
	ofs << "id " + oss2.str() << std::endl;
	
	ostringstream oss3;
	oss3 << priority;
	ofs << "priority " + oss3.str() << std::endl;

	ostringstream oss4;
	oss4 << status;
	ofs << "status " + oss4.str() << std::endl;
}