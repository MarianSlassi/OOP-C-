

#include "classfile.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Подключаем ввод на русском

	int punct = 0; //default user menu choice value
	int length; //length of dynami

	std::cout << "Пока не было создано объектов\nВведите количество объектов" << std::endl;
	length= Input();
	Product* arrS = new Product[length]; // array initializing
	vector <Order> orders;
	system("cls"); //clean console
	int red; // value to store object number in array to change his fields

	do {

		std::cout << "1. Просмотр объектов" << std::endl;
		std::cout << "2. Редактор объектов" << std::endl;
		std::cout << "3. Заказы" << endl;
		std::cout << "4. Выход \nВведите номер исполняемого действия: ";
		/*try
		{*/
		punct = InputMenu(1,4);
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
			JustShow(arrS, length);
			std::cout << "\n------------\n Всего объектов:" << length<< "\n Введите номер редактируемого объекта : ";
			red = InputMenu(1, length);
			cout << endl;
			arrS[red - 1].EditField();
			break;

		case 3:
			do {
				system("cls");
				cout << "Список заказчиков: " << endl;
				ShowOrders(orders);
				cout << "\n---------\n1. Создать пустой заказ\n2. Отменить последний добавленный заказ\n3. Редактировать заказ\n0. Выход" << endl;
				red = InputMenu(0, 3);
				
				Order def;//Просто пустой объект для работы с очередью
				switch (red)
				{
				case 1: 
					
					orders.push_back(def);
					break;
				case 2:
					 orders.pop_back();
					break;
				case 3:
					system("cls");
					ShowOrders(orders);
					cout << "Введите номер заказа который хотите редактировать" << endl;
					int i = InputMenu(1, orders.size());
					int k;
					int forpr;
					do {
						system("cls");
						orders.at(i-1).ShowShopInfo();
						cout << "\n-----\n1. Редактировать дату и имя\n2. Добавить в заказ товар\n3. Удалить последний добавленный товар\n4. Вывести дорогие товары\n0. Выход" << endl;
						
						k = InputMenu(0, 4);
						switch (k) 
						{
						case 1:
							
							
							orders[i-1].EditField();
							break;
						case 2:
							system("cls");
							JustShow(arrS, length);
							cout << "\nДобавить товар номер : ";
							cin >> forpr;
							orders[i-1].PushProduct(arrS[forpr - 1]);
							break;
						case 3:
							if (orders[i - 1].SizeOfList() == 0) { cout << "У вас пустой массив" << endl; Sleep(3000); continue; }
							cout << "\nУдалить товар номер : ";
							cin >> forpr;
							orders[i - 1].PopProduct(arrS[forpr - 1]);
							cout << "Товар удален";
							Sleep(3000);
							break;
						case 4:
							ShowExpensive(orders[i - 1]);
							Sleep(5000);
							break;
						}
					} while (k != 0);
					break;
					
					
				}
			} while (red != 0);
			
			break;
		
			delete[] arrS; // Всегда убирай за собой!
		}




		system("cls");


	} while (punct != 4 /* && cin*/);



	std::cout << "Работа программы завершена" << std::endl;



}









void OrderMenu() 
{

}


void Menu(int punct)
{

}