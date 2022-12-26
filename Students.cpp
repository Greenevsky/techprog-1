#include <iostream>
#include "Students.h"

using namespace std;

/*
std::string FCs;
	std::string group;
	std::string specialization;
	std::string course;
	float averageScore;
*/

Students::Students() : group(""), specialization(""), course(""), averageScore(0) {}
Students::Students(string fcs, string gr, string spec, string cour, float average) {
	this->FCs = fcs;
	this->group = gr;
	this->specialization = spec;
	this->course = cour;
	this->averageScore = average;
}
Students::Students(const Students& tmp) {
	this->FCs = tmp.FCs;
	this->group = tmp.group;
	this->specialization = tmp.specialization;
	this->course = tmp.course;
	this->averageScore = tmp.averageScore;
}
Students::~Students() {
	this->FCs = "";
	this->group = "";
	this->specialization = "";
	this->course = "";
	this->averageScore = 0;
}


void Students::set_group(std::string gr) { this->group = gr; }
void Students::set_specialization(std::string spec) { this->specialization = spec; }
void Students::set_course(std::string cour) { this->course = cour; }
void Students::set_averageScore(float average) { this->averageScore = average; }

std::string Students::get_group() { return this->group; }
std::string Students::get_specialization() { return this->specialization; }
std::string Students::get_course() { return this->course; }
float Students::get_averageScore() { return this->averageScore; }

void Students::out() {
	cout << "Student: " << endl;
	cout << "FCs: " << FCs << "\n" << "Group: " << group << "\n" <<
		"Specialization: " << specialization << "\n" <<
		"Coure: " << course << "\n" << "Average Score: " << averageScore << "\n";
}
void Students::change_d() {
	int id;
	out();
	cout << "Change a student: " << endl;
	cout << "1. FCs\n2.Group\n3.Specialization\n4.Course\n5.Average Score\n";
	cin >> id;
	switch (id) {
	case 1:
		change_b(1);
		break;
	case 2:
		cout << "Enter group: "; getline(cin, this->group);
		break;
	case 3:
		cout << "Enter specialization: "; getline(cin, this->specialization);
		break;
	case 4:
		cout << "Enter course: "; getline(cin, this->course);
		break;
	case 5:
		cout << "Enter average score: "; cin >> averageScore;
		break;
	default:
		throw exception("Error");
	}
}

string Students::info() { 
	string str;
	str = to_string(id) + "\n" + FCs + "\n" + group + "\n" + specialization + "\n" +
		course + "\n" + to_string(averageScore) + "\n";
	return str;
}