#include <iostream>
#include "Staff.h"

using namespace std;
/*
std::string FCs;
	std::string post;
	std::string phoneNum;
	std::string area;
*/

Staff::Staff() : post(""), phoneNum(""), area("") {}
Staff::Staff(std::string fcs, std::string post, std::string phone, std::string area) {
	this->FCs = fcs;
	this->post = post;
	this->phoneNum = phone;
	this->area = area;
}
Staff::Staff(const Staff& tmp) {
	this->FCs = tmp.FCs;
	this->post = tmp.post;
	this->phoneNum = tmp.phoneNum;
	this->area = tmp.area;
}
Staff::~Staff() {
	this->FCs = "";
	this->post = "";
	this->phoneNum = "";
	this->area = "";
}

void Staff::set_post(std::string post) { this->post = post; }
void Staff::set_phone(std::string phone) { this->phoneNum = phone; }
void Staff::set_area(std::string area) { this->area = area; }

std::string Staff::get_post() { return this->post; }
std::string Staff::get_phone() { return this->phoneNum; }
std::string Staff::get_area() { return this->area; }

void Staff::out() {
	cout << "FCs: " << FCs << "\n" << "Post: " << post << "\n" <<
		"Phone Number: " << phoneNum << "\n" << "Area: " << area << "\n";
}
void Staff::change_d() {
	int id;
	out();
	cout << "Change a staff: " << endl;
	cout << "1. FCs\n2.Post\n3.Phone Number\n4.Area\n";
	cin >> id;
	switch (id) {
	case 1:
		change_b(1);
		break;
	case 2:
		cout << "Enter group: "; getline(cin, this->post);
		break;
	case 3:
		cout << "Enter specialization: "; getline(cin, this->phoneNum);
		break;
	case 4:
		cout << "Enter course: "; getline(cin, this->area);
		break;
	default:
		throw exception("Error");
	}
}

string Staff::info() { 
	string str;
	str = FCs + "\n" + post + "\n" + phoneNum + "\n" + area + "\n";
	return str;
}