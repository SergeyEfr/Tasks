#pragma once
#include<iostream>
#include<fstream>
#include"TaskProperties.h"
#include<memory>
#include<wchar.h>
using namespace std;

class TaskProcedures
{
public:
    static ostream& write(ostream& os, shared_ptr<TaskProperties>& obj);
	static istream& read(istream& is, TaskProperties& obj);
	static shared_ptr<TaskProperties> taskCreate();
};