#pragma once
#include "University.h"
#include "Students.h"
#include "Teachers.h"
#include "Staff.h"

class Keeper {
	University** data;
	int SIZE;
	int INDEX;
public:
	Keeper();
	Keeper(int);
	Keeper(const Keeper&);
	~Keeper();

	void push_back(University&);
	void pop_back();
	void pop_by_index(int);

	void saveFile(std::string);
	void extractFile(std::string);
};