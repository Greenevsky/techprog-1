#pragma once
#include "University.h"

/*Для каждого преподавателя
определено: ФИО; перечислены группы, которые ведет; предметы, которые
преподает.*/
class Teachers : public University {
	std::vector <std::string> listGroup;
	std::vector <std::string> listSubject;

public:
	int id = 2;
	Teachers();
	Teachers(std::string, std::vector<std::string>, std::vector<std::string>);
	Teachers(const Teachers&);
	~Teachers();

	void set_listGroup(std::vector<std::string>);
	void set_listSubject(std::vector<std::string>);
	std::vector<std::string> get_listGroup();
	std::vector<std::string> get_listSubject();

	void out();
	void change_d();
	std::string info();
};
