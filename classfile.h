#pragma once
#include "include.h"


void ShowALL(Student* arrS, int length)  //function to show all object in array
{
	for (int i = 0; i < length; i++)
	{
		cout << "\n\n" << i + 1 << ".";
		arrS[i].ShowStudent();



	}
	cout << "----------------\nПросмотр будет завершен автоматически в течении десяти секунд\n------------------" << endl;
	Sleep(10000);
};

int Input() 
{
	int res;
	while (!(cin >> res))
	{
		cout << "Введите число а не символ" << endl;
		cin.clear();
		while (cin.get() != '\n');
	}

	return res;
};					//Function to let programm working even if input was char


Student::Student()
{
	this->name = "Данные неопределенны";
	this->groupNumber = "Данные неопределенны";
	this->averageGrade = 0;
	this->revenue = 0;

};				//default constructor

Student::Student(string name, string groupNumber, double averageGrade, int revenue)
{
	this->name = name;
	this->groupNumber = groupNumber;
	this->averageGrade = averageGrade;
	this->revenue = revenue;
};				//Constructor with inputs

Student::~Student()
{
};				//destructor

void Student::ShowStudent() 
{
	cout << "Имя: " << this->name << "\nНомер Группы: " << this->groupNumber << "\nСредний балл: " << this->averageGrade << "\nСредний доход на члена семьи: " << this->revenue<<"$" << endl;
};				//method to show certain object

void Student::Edit()
{
	string name, surname, lastname;
	cout << "\n Введите ФИО Студента" << endl;
	cin >> name;
	cin >> surname;
	cin >> lastname;
	this->name = name + " " + surname + " " + lastname;
	//Ввод ФИО студента
	cout << "\n Введите Букву Группы" << endl;
	string a;
	cin >> a;
	cout << "\n Введите Номер группы" << endl;
	string b;
	cin >> b;
	this->groupNumber = a + b;
	cout << "\n Введите Средний балл" << endl;
	cin >> this->averageGrade;
	cout << "\n Введите Средний доход на члена семьи в $" << endl;
	cin >> this->revenue;
}; //method to edit object fields

void GroupInput(Student st) 
{


	
}