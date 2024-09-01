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


ostream& TaskProcedures::write(ostream& os, shared_ptr<TaskProperties>& obj)

{
	os.write((char*)& (*obj).task_id, sizeof(obj->task_id));
	size_t s = obj->header.size();
	os.write((char*)&s, sizeof(s));
	os.write(obj->header.c_str(), s);

	s = obj->description.size();
	os.write((char*)&s, sizeof(s));
	os.write(obj->description.c_str(), s);

	string p = "";
	if (obj->priority == Priority::Low)
	{
		p = "Low";
	}
	else if (obj->priority == Priority::Medium)
	{
		p = "Medium";
	}
	else if (obj->priority == Priority::High)
	{
		p = "High";
	}
	cout << "write priority: " << p << endl;
	s = p.size();
	os.write((char*)&s, sizeof(s));
	os.write(p.c_str(), s);

	string c = "";
	if (obj->status == Status::Opened)
	{
		c = "Opened";
	}
	else if (obj->status == Status::InWork)
	{
		c = "InWork";
	}
	else if (obj->status == Status::Completed)
	{
		c = "Completed";
	}
	cout << "write status: " << c << endl;
	s = c.size();
	os.write((char*)&s, sizeof(s));
	os.write(c.c_str(), s);

	return os;
};

istream& TaskProcedures::read(istream& is, TaskProperties& obj)
{
	is.read((char*)&obj.task_id, sizeof(obj.task_id));
	size_t s = 0;
	is.read((char*)&s, sizeof(s));
	cout << "task_id: " << obj.task_id << endl;
	cout << "s: " << s << endl;
	try {
		char* buf = new char[s];
		is.read(buf, s);
		obj.header.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}

	is.read((char*)&s, sizeof(s));
	try {
		char* buf = new char[s];
		is.read(buf, s);
		obj.description.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}
	string p = "Hi";
	is.read((char*)&s, sizeof(s));
	try {
		char* buf = new char[s];
		is.read(buf, s);
		cout << "char p: ";
		for (int i = 0; i < s; i++)
		{
			cout << buf[i];
		}
		p.assign(buf, buf + s);
		cout << " read p: " << p << endl;
		delete[] buf;
		if (p == "Low")
		{
			obj.priority = Priority::Low;
		}
		else if (p == "Medium")
		{
			obj.priority = Priority::Medium;
		}
		else if (p == "High")
		{
			obj.priority = Priority::High;
		}
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}

	p = "Hi";
	is.read((char*)&s, sizeof(s));
	try {
		char* buf = new char[s];
		is.read(buf, s);
		cout << "char p: ";
		for (int i = 0; i < s; i++)
		{
			cout << buf[i];
		}
		p.assign(buf, buf + s);
		delete[] buf;
		if (p == "Opened")
		{
			obj.status = Status::Opened;
		}
		else if (p == "InWork")
		{
			obj.status = Status::InWork;
		}
		else if (p == "Completed")
		{
			obj.status = Status::Completed;
		}
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}

};

 shared_ptr <TaskProperties> TaskProcedures::taskCreate()
{
	unsigned int id;
	cout << "Enter task_id: " << endl;
	cin >> id;
	cout << endl;
	cin.ignore();
	string header;
	cout << "Enter the header: " << endl;
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
	cout << "status after entering: " << s << endl;
	shared_ptr<TaskProperties> task = make_shared<TaskProperties>(id, header.c_str(), description.c_str(), p, s);
	return task;
};
