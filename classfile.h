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
	this->name = "Данные неопределенны";
	this->groupNumber = "Данные неопределенны";
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
	cout << "Имя: " << this->name << "\nНомер Группы: " << this->groupNumber << "\nСредний балл: " << this->averageGrade << "\nСредний доход на члена семьи: " << this->revenue<<"$" << endl;

};

void Student::Edit() 
{
	cout << "\n Введите Имя Студента" << endl;
	cin >> this->name;
	cout << "\n Введите Номер Группы" << endl;
	cin >> this->groupNumber;
	cout << "\n Введите Средний балл"<<endl;
	cin >> this->averageGrade;
	cout << "\n Введите Средний доход на члена семьи в $" << endl;
	cin >> this->revenue;
}