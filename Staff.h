#pragma once
#include "University.h"


/*Для административного персонала определено: ФИО, должность,
телефон, область ответственности.*/
class Staff : public University {
	std::string post;
	std::string phoneNum;
	std::string area;

public:
	int id = 3;
	Staff();
	Staff(std::string, std::string, std::string, std::string);
	Staff(const Staff&);
	~Staff();

	void set_post(std::string);
	void set_phone(std::string);
	void set_area(std::string);

	std::string get_post();
	std::string get_phone();
	std::string get_area();

	void out();
	void change_d();
	std::string info();
};