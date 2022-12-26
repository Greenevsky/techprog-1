#include <iostream>
#include <fstream>
#include "Keeper.h"

using namespace std;

Keeper::Keeper() : SIZE(0), INDEX(0), data(NULL) {}
Keeper::Keeper(int sz) : SIZE(sz), INDEX(0), data(new University* [SIZE]) {}
Keeper::Keeper(const Keeper& tmp) {
	this->SIZE = tmp.SIZE;
	this->INDEX = tmp.INDEX;
	this->data = tmp.data;
}
Keeper::~Keeper() {
	if (SIZE = 0)
		return;
	for (int i = 0; i < INDEX; i++)
		delete(data[i]);
	delete[] data;
	SIZE = 0;
	INDEX = 0;
}

void Keeper::push_back(University& new_data) {
	if (INDEX == SIZE) {
		SIZE++;
		University** tmp_data = new University * [SIZE];
		for (int i = 0; i < INDEX; i++)
			tmp_data[i] = data[i];
		tmp_data[INDEX] = &new_data;
		data = tmp_data;
		INDEX++;
	}
	else {
		data[INDEX] = &new_data;
		INDEX++;
	}
}

void Keeper::pop_back() {
	if (!INDEX)
		return;
	delete(data[INDEX - 1]);
	INDEX--;
}

void Keeper::pop_by_index(int id) {
	id--;
	University** tmp_data = new University * [SIZE];
	for (int i = 0, j = 0; j < INDEX; i++, j++) {
		if (id == i)
			j++;
		tmp_data[i] = data[j];
	}
	data = tmp_data;
	INDEX--;
}


void Keeper::saveFile(string pth) {
	ofstream f(pth);

	f << INDEX << "\n";
	for (int i = 0; i < INDEX; i++)
		f << data[i]->info();

	f.close();
}
void Keeper::extractFile(string pth) {
	/*var*/
	string FCs;
	/*students*/
	string group;
	string specialization;
	string course;
	float averageScore;
	/*teachers*/
	std::vector <std::string> listGroup;
	std::vector <std::string> listSubject;
	/*staff*/
	string post;
	string phoneNum;
	string area;

	int id;
	int sz_v;
	string tmp_v;

	ifstream f(pth);
	if (!f.is_open())
		return;
	f >> SIZE;
	University* bf = NULL;

	for (int i = 0; i < SIZE; i++) {
		f >> id;
		switch (id) {
		case 1: //students
			getline(f, FCs);
			getline(f, group);
			getline(f, specialization);
			getline(f, course);
			f >> averageScore;
			bf = new Students(FCs, group, specialization, course, averageScore);
			break;
		case 2: //teachers
			getline(f, FCs);
			f >> sz_v;
			for (int i = 0; i < sz_v; i++) {
				getline(f, tmp_v);
				listGroup.push_back(tmp_v);
			}
			f >> sz_v;
			for (int i = 0; i < sz_v; i++) {
				getline(f, tmp_v);
				listSubject.push_back(tmp_v);
			}
			bf = new Teachers(FCs, listGroup, listSubject);
				break;
		case 3: //staff
			getline(f, FCs);
			getline(f, post);
			getline(f, phoneNum);
			getline(f, area);
			bf = new Staff(FCs, post, phoneNum, area);
			break;
		}
		push_back(*bf);
	}
	f.close();
}