#include<iostream>
#include<fstream>
#include"TaskProperties.h"
#include"TaskProcedures.h"
#include <memory>
using namespace std;

int main()
{
	Priority p2 = Priority::High;
	Status s2 = Status::Completed;
	TaskProperties b(2, "Test task", "Test Description", p2, s2);

	string path;
	cout << "Enter the path to file, where to write the object" << endl;
	cin >> path;
	ofstream out(path, ios::binary);
	shared_ptr<TaskProperties> a = make_shared<TaskProperties>(TaskProcedures::taskCreate);
	TaskProcedures::write(out, a);
	out.close();

	cout << "Enter the path to file, from where the object is being read" << endl;
	cin >> path;
	ifstream in(path, ios::binary);
	TaskProcedures::read(in, b);
	in.close();

	cout << "b.task_id: " << b.task_id << endl;
	cout << "b.header: " << b.header << endl;
	cout << "b.description: " << b.description << endl;
	cout << "b.priority: " << b.priority << endl;
	cout << "b.status: " << b.status << endl;

	return 0;
}