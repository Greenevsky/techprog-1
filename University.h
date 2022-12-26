#pragma once
#include <string>
#include <vector>

/*
����� ��� ������ ������ �� ���������, �������������� � �����������������
���������. ��� ������� �������� ����������: ���, ������, ������������
�������������, ������� ����, ������� ����. ��� ������� �������������
����������: ���; ����������� ������, ������� �����; ��������, �������
���������. ��� ����������������� ��������� ����������: ���, ���������,
�������, ������� ���������������.
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
