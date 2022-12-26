#include <iostream>
#include "Teachers.h"

using namespace std;

Teachers::Teachers() { listGroup.clear(); listSubject.clear(); }
Teachers::Teachers(string fcs, vector<std::string> gr, vector<std::string> sub) {
	this->FCs = fcs;
	this->listGroup = gr;
	this->listSubject = sub;
}
Teachers::Teachers(const Teachers& tmp) {
	this->FCs = tmp.FCs;
	this->listGroup = tmp.listGroup;
	this->listSubject = tmp.listSubject;
}
Teachers::~Teachers() {
	this->FCs = "";
	listGroup.clear();
	listSubject.clear();
}

void Teachers::set_listGroup(std::vector<std::string> gr) { this->listGroup = gr; }
void Teachers::set_listSubject(std::vector<std::string> sub) { this->listSubject = sub; }
std::vector<std::string> Teachers::get_listGroup() { return this->listGroup; }
std::vector<std::string> Teachers::get_listSubject() { return this->listSubject; }

void Teachers::out() {
	cout << "FCs: " << FCs << "\n";
	cout << "List of group: " << "\n";
	for (int i = 0; i < listGroup.size(); i++)
		cout << listGroup[i] << "\n";
	cout << "List of subject: " << "\n";
	for (int i = 0; i < listSubject.size(); i++)
		cout << listSubject[i] << "\n";
}
void Teachers::change_d() {
	int id;
	int sz_v;
	string tmp_v;
	out();
	cout << "Change a teacher: " << endl;
	cout << "1. FCs\n2.List of group\n3.List of subjects\n";
	cin >> id;
	switch (id) {
	case 1:
		change_b(1);
		break;
	case 2:
		cout << "Enter number of group: ";
		cin >> sz_v;
		if (sz_v < 0)
			break;
		for (int i = 0; i < sz_v; i++) {
			getline(cin, tmp_v);
			listGroup.push_back(tmp_v);
		}
		break;
	case 3:
		cout << "Enter number of subjects: ";
		cin >> sz_v;
		if (sz_v < 0)
			break;
		for (int i = 0; i < sz_v; i++) {
			getline(cin, tmp_v);
			listSubject.push_back(tmp_v);
		}
		break;
	default:
		throw exception("Error");
	}
}

string Teachers::info() {
	string str;
	str = FCs + "\n";
	str += (listGroup.size() + "\n");
	for (int i = 0; i < listGroup.size(); i++)
		str += (listGroup[i] + "\n");
	str += (listSubject.size() + "\n");
	for (int i = 0; i < listSubject.size(); i++)
		str += (listSubject[i] + "\n");
	return str;
}