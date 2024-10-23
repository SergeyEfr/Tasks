#pragma once
#include<iostream>
#include<fstream>
using namespace std;

enum Priority { Low, Medium, High };
enum Status {Opened, InWork, Completed };
ostream& operator << (ostream& os, const Priority& p);
ostream& operator << (ostream& os, const Status& p);
class TaskProperties
{
public:
	TaskProperties(unsigned int id, const char* h, const char* d, Priority& p, Status& s) : task_id(id), header(h), description(d), priority(p), status(s) {};
	TaskProperties() : task_id(0), header(""), description(""), priority(Low), status(Opened) {}
	size_t task_id;
	string header;
	string description;
	Priority priority;
	Status status;
	
	void TaskShow();
	
};

