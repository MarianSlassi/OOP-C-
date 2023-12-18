
#include "classfile.h"




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Подключаем ввод на русском

	int punct = 0; //default user menu choice value
	int length; //length of dynami

	std::cout << "Введите количество студентов" << std::endl;
	std::cin >> length;
	Student* arrS = new Student[length]; // array initializing
	
	system("cls"); //clean console
	int red; // value to store object number in array to change his fields
	
	do  {

		std::cout << "1. Просмотр объектов" << std::endl;
		std::cout << "2. Редактор списка студентов" << std::endl;
		std::cout << "3. Выход \nВведите номер исполняемого действия" <<std::endl;
		/*try
		{*/
			punct = Input();
		/*}
		catch (const std::exception& ex)
		{
			cout<< ex.what()<<endl;
			cout << "Ошибка ввода" << endl;
		}
		*/
		
		switch (punct)
		{
		case 1:
			if (length == 0)
			{
				std::cout << "Еще не было создано объектов" << std::endl;
				
				Sleep(2000);
				break;
			}
			else ShowALL(arrS, length);

			break;

		case 2:
			
			std::cout << "Введите номер редактируемого студента \n Всего студентов: "<<length+1<<std::endl;
			red=Input();
			arrS[red - 1].Edit();
			break;
		

		default:
			cout << "Введите еще раз, только число из пункта меню" << endl;
			punct = Input();
			break;


			delete[] arrS; // Всегда убирай за собой!
		}
		

		
		
		system("cls");


	} while (punct != 3 /* && cin*/);

	
	
	std::cout << "Работа программы завершена" << std::endl;


	
}
