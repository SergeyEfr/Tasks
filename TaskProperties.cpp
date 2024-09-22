#include"TaskProperties.h"

ostream& operator << (ostream& os, const Priority& p)
{
	switch (p)
	{
	case 0: {os << "Low"; break; }
	case 1: {os << "Medium"; break; }
	case 2: {os << "High"; break; }
	}
	return os;
}

ostream& operator << (ostream& os, const Status& p)
{
	switch (p)
	{
	case 0: {os << "Opened"; break; }
	case 1: {os << "InWork"; break; }
	case 2: {os << "Completed"; break; }
	}
	return os;
}

void TaskProperties::TaskShow()
{
	cout << "id: " << this->task_id << endl;
	cout << "Header: " << this->header << endl;
	cout << "Description: " << this->description << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority: " << this->priority << endl;
}

