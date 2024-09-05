#include"TaskProcedures.h"

istream& operator >> (istream& is, Priority& p)
{
	string s = "";
	is >> s;
	if (s == "Low")
	{
		p= Priority::Low;
	}
	else if (s == "Medium")
	{
		p= Priority::Medium;
	}
	else if (s == "High")
	{
		p= Priority::High;
	}
	else
	{
		cout << "Enter the correct priority!";
	}
	return is;
}

istream& operator >> (istream& is, Status& f)
{
	string s = "";
	is >> s;
	if (s == "Opened")
	{
		f = Status::Opened;
	}
	else if (s == "InWork")
	{
		f = Status::InWork;
	}
	else if (s == "Completed")
	{
		f = Status::Completed;
	}
	else
	{
		cout << "Enter the correct priority!";
	}
	return is;
}


ostream& TaskProcedures::write(ostream& os, const shared_ptr <TaskProperties> obj)

{
	os.write((char*)& (*obj).task_id, sizeof(obj->task_id));
	size_t s = obj->header.size();
	os.write((char*)&s, sizeof(s));
	os.write(obj->header.c_str(), s);

	s = obj->description.size();
	os.write((char*)&s, sizeof(s));
	os.write(obj->description.c_str(), s);

	os.write((char*)& obj->priority, sizeof(obj->priority));
	os.write((char*)& obj->status, sizeof(obj->status));
	
	return os;
};

istream& TaskProcedures::read(istream& is, const shared_ptr <TaskProperties> obj)
{
	is.read((char*)& obj->task_id, sizeof(obj->task_id));
	size_t s = 0;
	is.read((char*)&s, sizeof(s));
	try {
		char* buf = new char[s];
		is.read(buf, s);
		obj->header.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}

	is.read((char*)&s, sizeof(s));
	try {
		char* buf = new char[s];
		is.read(buf, s);
		obj->description.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}
	is.read((char*)& obj->priority, sizeof(obj->priority));
	is.read((char*)&obj->status, sizeof(obj->status));
	
};

 shared_ptr <TaskProperties> TaskProcedures::taskCreate()
{
	unsigned int id;
	cout << "Enter task_id: " << endl;
	cin >> id;
	cout << endl;
	cin.ignore();
	string header;
	cout << "Enter the header of task: " << endl;
	getline(cin, header);
	string description;
	cout << "Enter the description: " << endl;
	getline(cin, description);
	cin.clear();
	Priority p;
	cout << "Enter priority: ";
	cin >> p;
	cin.clear();
	cout << "Enter status: ";
	cin.clear();
	Status s;
	cin >> s;
	auto task = make_shared<TaskProperties>(id, header.c_str(), description.c_str(), p, s);
	return task;
};

