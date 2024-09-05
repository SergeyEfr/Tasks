#include<iostream>
#include<fstream>
#include"TaskProperties.h"
#include"TaskProcedures.h"
#include <memory>
#include<vector>
#include <map>
#include<unordered_map>
#include <unordered_set>
#include <hash_map>
using namespace std;

int main()
{
	
	string path;
	cout << "Enter the path to file, where to write the object" << endl;
	cin >> path;

	unordered_map <Priority, unordered_set<TaskProperties>> priority_map;
	vector<shared_ptr<TaskProperties>> tasks;
	ofstream out(path, ios::binary);
	int f = 0;
	while (f != 2)
	{

		cout<<"Enter 1 for Creating of the Task and 2 to Exit from The Program: \n";
		cin >> f;
		if (f == 1)
		{
			
			shared_ptr<TaskProperties> a = TaskProcedures::taskCreate();
			tasks.push_back(a);
			TaskProcedures::write(out, a);
			
		}
	}
	out.close();

	vector<shared_ptr<TaskProperties>> test_tasks;
	ifstream in(path, ios::binary);
	while (!in.eof())
	{
		Priority p2 = Priority::High;
		Status s2 = Status::Completed;
		shared_ptr<TaskProperties> b = make_shared<TaskProperties>(2, "Test Task", "Test Description", p2, s2);
		TaskProcedures::read(in, b);
		test_tasks.push_back(b);
	}
	in.close();

	for (shared_ptr<TaskProperties> task : test_tasks)
	{
		cout << "id: " << task->task_id << endl;
		cout << "header: " << task->header << endl;
		cout << "description: " << task->description << endl;
		cout << "priority: " << task->priority << endl;
		cout << "status: " << task->status << endl;
	}
	
	

	return 0;
}