#pragma once
#include "University.h"

/*Для каждого студента определено: ФИО, группа, наименование
специальности, текущий курс, средний балл.*/
class Students : public University {
	std::string group;
	std::string specialization;
	std::string course;
	float averageScore;

public:
	int id = 1;
	Students();
	Students(std::string, std::string, std::string, std::string, float);
	Students(const Students&);
	~Students();

	void set_group(std::string);
	void set_specialization(std::string);
	void set_course(std::string);
	void set_averageScore(float);

	std::string get_group();
	std::string get_specialization();
	std::string get_course();
	float get_averageScore();

	void out();
	void change_d();
	std::string info();
};
