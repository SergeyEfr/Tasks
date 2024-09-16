#include"TaskProcedures.h"
#include <string_view>

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

bool TaskProcedures::read(istream& is, const shared_ptr <TaskProperties> obj)
{
	if (!is.read((char*)&obj->task_id, sizeof(obj->task_id)))
	{
		return false;
	}
	
	size_t s = 0;
	if(!is.read((char*)&s, sizeof(s)))
	{
		return false;
	}
	try {
		char* buf = new char[s];
		if (!is.read(buf, s))
		{
			return false;
		}
		obj->header.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}

	if (!is.read((char*)&s, sizeof(s)))
	{
		return false;
	}
	try {
		char* buf = new char[s];
		if (!is.read(buf, s))
		{
			return false;
		}
		obj->description.assign(buf, buf + s);
		delete[] buf;
	}
	catch (bad_alloc& exception) {
		cerr << "bad_alloc detected: " << exception.what();
	}
	if (!is.read((char*)&obj->priority, sizeof(obj->priority)))
	{
		return false;
	}
	if (!is.read((char*)&obj->status, sizeof(obj->status)))
	{
		return false;
	}
	return true;
};

 shared_ptr <TaskProperties> TaskProcedures::taskCreate()
{
	unsigned int id;
	cout << "Enter task_id: " << endl;
	while (true)
	{
		cin >> id;
		if (tasks.count(id) != 0)
		{
			cout << "There is alredy such an id! Enter another id: " << endl;
		}
		else
		{
			break;
		}
	}
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

 void TaskProcedures::taskCreateAction()
 {

	 shared_ptr<TaskProperties> a = taskCreate();
	 tasks.insert({ a->task_id, a });
 }

 void TaskProcedures::taskErasing()
 {
	 size_t id = 0;
	 cout << "Enter id of the Task for erasing: " << endl;
	 cin.clear();
	 cin >> id;
	 tasks.erase(id);
 }

 void TaskProcedures::taskEdit()
 {
	 size_t id = 0;
	 cout << "Enter id of the Task for Edit: " << endl;
	 cin.clear();
	 cin >> id;
	 cin.clear();
	 string field;
	 cout << "Enter one of the properties to edit:\n \"header\", \"description\", \"priority\", \"status\" " << endl;
	 cin >> field;
	 if (field == "header")
	 {
		 cin.ignore();
		 string new_header;
		 cout << "Enter new header: " << endl;
		 getline(cin, new_header);
		 tasks[id]->header = new_header;
	 }
	 else if(field == "description")
	 {
		 cin.ignore();
		 string new_description;
		 cout << "Enter new description: " << endl;
		 getline(cin, new_description);
		 tasks[id]->description = new_description;
	 }
	 else if (field == "priority")
	 {
		 cin.ignore();
		 cout << "Enter new priority: " << endl;
		 Priority p;
		 cin >> p;
		 tasks[id]->priority = p;
	 }
	 else if(field == "status")
	 {
		 cin.ignore();
		 cout << "Enter new status: " << endl;
		 Status s;
		 cin >> s;
		 tasks[id]->status = s;
	 }
 }

 void TaskProcedures::allTasksOutput()
 {
	 cout << "All Tasks: \n";
	 for (auto element : tasks)
	 {
		 cout << "The Task with id " << element.second->task_id << ":\n";
		 cout << "Header: " << element.second->header << endl;
		 cout << "Description: " << element.second->description << endl;
		 cout << "Status: " << element.second->status << endl;
		 cout << "Priority: " << element.second->priority << endl;
		 cout << "\n";
	 }
 }
 void TaskProcedures::tasksFilter()
 {
	 cout<<"Enter 1 for task filter with status and enter 2 for task filter with priority: " << endl;
	 int f = 0;
	 cin >> f;
	 if (f == 2)
	 {
		 cin.ignore();
		 cout << "Enter priority filter(\"Low\", \"Medium\", \"High\"):\n";
		 Priority p;
		 cin >> p;
		 cout << "Tasks with priority " << p << ":\n";
		 auto p_set = priority_map[p];
		 for (auto it = p_set.begin(); it != p_set.end(); ++it)
		 {
			 cout << *it << "\n";
			 auto task = tasks[*it];
			 cout << "id " << *it << endl;
			 cout << "Header: " << task->header << endl;
			 cout << "Description: " << task->description << endl;
			 cout << "Status: " << task->status << endl;
			 cout << "Priority: " << task->priority << endl;
		 }
	 }
	 else if (f == 1)
	 {
		 cin.ignore();
		 cout << "Enter status filter(\"Opened\", \"InWork\", \"Completed\"):\n ";
		 Status s;
		 cin >> s;
		 cout << "Tasks with status " << s << ":\n";
		 auto s_set = status_map[s];

		 for (auto it = s_set.begin(); it != s_set.end(); ++it)
		 {
			 cout << *it << "\n";
			 auto task = tasks[*it];
			 cout << "id " << *it << endl;
			 cout << "Header: " << task->header << endl;
			 cout << "Description: " << task->description << endl;
			 cout << "Status: " << task->status << endl;
			 cout << "Priority: " << task->priority << endl;
		 }
	 }
 }

 void TaskProcedures::taskSearch()
 {
	 cout << "Enter id for Searh of Task: " << endl;
	 size_t id = 0;
	 cin.ignore();
	 cin >> id;
	 cout << "Task with id " << id << ":\n";
	 cout << "Header: " << tasks[id]->header << endl;
	 cout << "Description: " << tasks[id]->description << endl;
	 cout << "Status: " << tasks[id]->status << endl;
	 cout << "Priority: " << tasks[id]->priority << endl;

 }

 void TaskProcedures::taskHeaderContentSearch()
 {
	 cout << "Enter header content for Search of Task: " << endl;
	 string content;
	 cin.ignore();
	 getline(cin, content);
	 
	 for (auto element : tasks)
	 {
		 string text = element.second->header;
		 if (text.find(content) != string::npos)
		 {
			 cout << "Task with header content \"" << content << "\":\n";
			 cout << "id: " << element.second->task_id << endl;
			 cout << "Header: " << element.second->header << endl;
			 cout << "Description: " << element.second->description << endl;
			 cout << "Status: " << element.second->status << endl;
			 cout << "Priority: " << element.second->priority << endl;
		 }
	 }
 }

 void TaskProcedures::taskDescriptionContentSearch()
 {
	 cout << "Enter description content for Search of Task: " << endl;
	 string content;
	 cin.ignore();
	 getline(cin, content);

	 for (auto element : tasks)
	 {
		 string text = element.second->description;
		 if (text.find(content) != string::npos)
		 {
			 cout << "Task with description content \"" << content << "\":\n";
			 cout << "id: " << element.second->task_id << endl;
			 cout << "Header: " << element.second->header << endl;
			 cout << "Description: " << element.second->description << endl;
			 cout << "Status: " << element.second->status << endl;
			 cout << "Priority: " << element.second->priority << endl;
		 }
	 }
 }

