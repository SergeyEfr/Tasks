#include<iostream>
#include<fstream>
#include"TaskProperties.h"
#include"TaskProcedures.h"
#include <memory>
#include<vector>
#include <map>

using namespace std;

int main()
{
	
	string path;
	cout << "Enter the path to file, where to write the object" << endl;
	cin >> path;
	TaskProcedures* proc = new TaskProcedures();
	
	ifstream in(path, ios::binary);
	while (true)
	{

		Priority p2 = Priority::High;
		Status s2 = Status::Completed;
		shared_ptr<TaskProperties> b = make_shared<TaskProperties>(2, "Test Task", "Test Description", p2, s2);
		if (!proc->read(in, b))
		{
			break;
		}
		proc->tasks.insert({ b->task_id, b });
		proc->status_map[b->status].insert(b->task_id);
		proc->priority_map[b->priority].insert(b->task_id);
	}
	in.close();

	for (auto element : proc->tasks)
	{
		cout << "id: " << element.second->task_id << endl;
		cout << "header: " << element.second->header << endl;
		cout << "description: " << element.second->description << endl;
		cout << "priority: " << element.second->priority << endl;
		cout << "status: " << element.second->status << endl;
	}

	
	int f = 0;
	while (f != 2)
	{
		cout<<"Enter:\n 1 for Creating of the Task\n 2 to Exit from The Program\n 3 for erasing of the Task\
        \n 4 for the task edit\n 5 for Output of all Tasks\n 6 for Output Tasks with Filter\n 7 for Search of Task with id\
        \n 8 for Task Header Content Search\n 9 for Task Description Content Search:\n";
		cin >> f;
		if (f == 1)
		{
			proc->taskCreateAction();
		}
		else if (f == 3)
		{
			proc->taskErasing();
			
		}
		else if (f == 4)
		{
			proc->taskEdit();
		}
		else if (f == 5)
		{
			proc->allTasksOutput();
		}
		else if (f == 6)
		{
			proc->tasksFilter();
		}
		else if (f == 7)
		{
			proc->taskSearch();
		}
		else if (f == 8)
		{
			proc->taskHeaderContentSearch();
		}
		else if (f == 9)
		{
			proc->taskDescriptionContentSearch();
		}
	}

	ofstream out(path, ios::binary);
	for (auto element : proc->tasks)
	{
		proc->write(out, element.second);
	}
	out.close();

	return 0;
}