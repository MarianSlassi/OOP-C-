#pragma once
#include "include.h"


class Student
{
public:
	Student();
	Student(string name, string groupNumber, double averageGrade, int revenue);
	~Student();
	void ShowStudent();
	void Edit();
private:
	string name;
	string groupNumber;
	double averageGrade;
	int revenue;
};

Student::Student()
{
	this->name = "������ �������������";
	this->groupNumber = "������ �������������";
	this->averageGrade = 0;
	this->revenue = 0;

};
Student::Student(string name, string groupNumber, double averageGrade, int revenue)
{
	this->name = name;
	this->groupNumber = groupNumber;
	this->averageGrade = averageGrade;
	this->revenue = revenue;
};

Student::~Student()
{
};

void Student::ShowStudent() {
	cout << "���: " << this->name << "\n����� ������: " << this->groupNumber << "\n������� ����: " << this->averageGrade << "\n������� ����� �� ����� �����: " << this->revenue<<"$" << endl;

};

void Student::Edit() 
{
	cout << "\n ������� ��� ��������" << endl;
	cin >> this->name;
	cout << "\n ������� ����� ������" << endl;
	cin >> this->groupNumber;
	cout << "\n ������� ������� ����"<<endl;
	cin >> this->averageGrade;
	cout << "\n ������� ������� ����� �� ����� ����� � $" << endl;
	cin >> this->revenue;
}