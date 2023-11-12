#pragma once
#include "include.h"


void ShowALL(Student* arrS, int length)  //function to show all object in array
{
	for (int i = 0; i < length; i++)
	{
		cout << "\n\n" << i + 1 << ".";
		arrS[i].ShowStudent();



	}
	cout << "----------------\n�������� ����� �������� ������������� � ������� ������ ������\n------------------" << endl;
	Sleep(10000);
};

int Input() 
{
	int res;
	while (!(cin >> res))
	{
		cout << "������� ����� � �� ������" << endl;
		cin.clear();
		while (cin.get() != '\n');
	}

	return res;
};					//Function to let programm working even if input was char


Student::Student()
{
	this->name = "������ �������������";
	this->groupNumber = "������ �������������";
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
	cout << "���: " << this->name << "\n����� ������: " << this->groupNumber << "\n������� ����: " << this->averageGrade << "\n������� ����� �� ����� �����: " << this->revenue<<"$" << endl;
};				//method to show certain object

void Student::Edit()
{
	string name, surname, lastname;
	cout << "\n ������� ��� ��������" << endl;
	cin >> name;
	cin >> surname;
	cin >> lastname;
	this->name = name + " " + surname + " " + lastname;
	//���� ��� ��������
	cout << "\n ������� ����� ������" << endl;
	string a;
	cin >> a;
	cout << "\n ������� ����� ������" << endl;
	string b;
	cin >> b;
	this->groupNumber = a + b;
	cout << "\n ������� ������� ����" << endl;
	cin >> this->averageGrade;
	cout << "\n ������� ������� ����� �� ����� ����� � $" << endl;
	cin >> this->revenue;
}; //method to edit object fields

void GroupInput(Student st) 
{


	
}