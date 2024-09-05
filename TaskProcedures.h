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
    static ostream& write(ostream& os, const shared_ptr <TaskProperties> obj);
	static istream& read(istream& is, const shared_ptr <TaskProperties> obj);
	static shared_ptr<TaskProperties> taskCreate();
};