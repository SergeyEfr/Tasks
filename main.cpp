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
	
	TaskProcedures proc;
	proc.tasksReading();
	
	int f = 0;
	while (f != 2)
	{
		cout<<"Enter:\n 1 for Creating of the Task\n 2 to Exit from The Program\n 3 for erasing of the Task\
        \n 4 for the task edit\n 5 for Output of all Tasks\n 6 for Output Tasks with Filter\n 7 for Search of Task with id\
        \n 8 for Task Header Content Search\n 9 for Task Description Content Search:\n";
		cin >> f;
		if (f == 1)
		{
			proc.taskCreateAction();
			proc.tasksChangeSave();
		}
		else if (f == 3)
		{
			proc.taskErasing();
			proc.tasksChangeSave();
		}
		else if (f == 4)
		{
			proc.taskEdit();
			proc.tasksChangeSave();
		}
		else if (f == 5)
		{
			proc.allTasksOutput();
		}
		else if (f == 6)
		{
			proc.tasksFilter();
		}
		else if (f == 7)
		{
			proc.taskSearch();
		}
		else if (f == 8)
		{
			proc.taskHeaderContentSearch();
		}
		else if (f == 9)
		{
			proc.taskDescriptionContentSearch();
		}
	}
	proc.tasksChangeSave();
	
	return 0;
}