#pragma once
#include<iostream>
#include<fstream>
using namespace std;

enum Priority { Low, Medium, High };
enum Status {Opened, InWork, Completed };
class TaskProperties
{
public:
	TaskProperties(unsigned int id, const char* h, const char* d, Priority& p, Status& s) : task_id(id), header(h), description(d), priority(p), status(s) {};
	size_t task_id;
	string header;
	string description;
	Priority priority;
	Status status;
	
};