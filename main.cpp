
#include "classfile.h"





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int punct = 0; //user menu choice
	std::cout << "Введите количество студентов" <<std::endl;
	int length;
	std::cin>> length;
	Student *arrS = new Student[length]; //objects volume
	system("cls");
	int red;
	
	do  {

		std::cout << "1. Просмотр объектов" << std::endl;
		std::cout << "2. Редактор списка студентов" << std::endl;
		std::cout << "3. Выход \nВведите номер исполняемого действия" <<std::endl;
		std::cin >> punct;
		
		
		switch (punct)
		{
		case 1:
			if (length == NULL) 
			{
				std::cout << "Еще не было создано объектов" << std::endl;
				break;
				Sleep(2000);
			}
			else for (int i = 0; i < length; i++) 
			{
				cout <<"\n\n"<< i + 1 << ".";
				arrS[i].ShowStudent();
				


			}
			cout << "----------------\nПросмотр будет завершен автоматически в течении десяти секунд\n------------------" << endl;
			Sleep(10000);

			break;

		case 2:

			std::cout << "Введите номер редактируемого студента \n Всего студентов: "<<length+1<<std::endl;
			std::cin >> red;
			arrS[red - 1].Edit();
			break;
		


		}
		
		
		system("cls");


	} while (punct != 3);

	delete[] arrS;
	
	std::cout << "Работа программы завершена" << std::endl;


	
}
