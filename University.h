#pragma once
#include <string>
#include <vector>

/*
Класс ВУЗ хранит данные по студентам, преподавателям и административному
персоналу. Для каждого студента определено: ФИО, группа, наименование
специальности, текущий курс, средний балл. Для каждого преподавателя
определено: ФИО; перечислены группы, которые ведет; предметы, которые
преподает. Для административного персонала определено: ФИО, должность,
телефон, область ответственности.
*/

class University {
protected:
	std::string FCs;

public:
	University();
	University(std::string);
	University(const University&);
	virtual ~University();

	void set_FCs(std::string);
	std::string get_FCs();

	virtual void out() = 0;
	virtual void change_d() = 0;
	void change_b(int);
	virtual std::string info() = 0;
};
