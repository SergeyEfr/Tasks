#pragma once
#include<iostream>
#include<fstream>
#include"TaskProperties.h"
#include<memory>
#include<wchar.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TaskProcedures
{
public:
	unordered_map <size_t, shared_ptr<TaskProperties>> tasks;
	unordered_map <Status, unordered_set<size_t>> status_map;
	unordered_map <Priority, unordered_set <size_t>> priority_map;
	string path;

    ostream& write(ostream& os, const shared_ptr <TaskProperties> obj);
	bool read(istream& is, const shared_ptr <TaskProperties> obj);
	shared_ptr<TaskProperties> taskCreate();
	void taskCreateAction();
	void taskErasing();
	void taskEdit();
	void allTasksOutput() const;
	void tasksFilter() const;
	void taskSearch() const;
	void taskHeaderContentSearch() const;
	void taskDescriptionContentSearch() const;
	void tasksChangeSave();
	void tasksReading();
};