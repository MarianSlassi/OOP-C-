#pragma once

#include "include.h"
//----------------------------------------------------------------------
int Input()
{
	int res;
	while (!(cin >> res) )
	{
		cout << "Вы ввели неподходящее значение" << endl;
		cin.clear();
		while (cin.get() != '\n');
	}

	return res;
};			                                                //Function to let programm working even if input was char
int InputMenu(int min, int max) {
	int menu = Input();
	while (menu > max or menu < min)
	{
		cout << "Выберите пункт меню" << endl;
		menu = Input();
	}
	return menu;
}

                                                            //DEFAULT CONSTRUCTOR
Product::Product()
{
	this->name = "Нет данных о наименование товара";
	this->category = "Нет данных о категории товара";
	this->amount = 0;
	this->price = 0;
	this->date = "Нет данных о поступлении товара на склад";
};


Product::~Product()                                          //DESTRUCTOR
{

}

//CONSTRUCTOR WITH PARAMETERS
Product::Product(string name, string category, int amount, double price, string date)
{
	this->name = name;
	this->category = category;
	this->amount = amount;
	this->price = price;
	this->date = date;
}





                   //----------------------------GET AND SET------------------------------------------
                                                                        //GET GUNCTIONS
string Product::GetName()
{
	return name;
}
string Product::GetCategory()
{
	return category;
}
string Product::GetDate()
{
	return date;
}
int Product::GetAmount()
{
	return amount;
}
double Product::GetPrice()
{
	return price;
}

																				//SET FUNCTIONS
void Product::SetName(string name)
{
	this->name = name;
}
void Product::SetCategory(string category)
{
	this->category = category;
}
void Product::SetDate(string date)
{
	this->date = date;
}
void Product::SetAmount(int amount)
{
	this->amount = amount;
}
void Product::SetPrice(double price)
{
	this->price = price;
}

								//---------------------SHOWING METHODS-------------------------------------------------



														//Method to show certain Object
void Product::ShowProduct()
{
	cout << "Наименование: " << this->name << "\nКатегория: " << this->category << "\nКоличество: " << this->amount << " шт\n" << "Стоимость: " << this->price << " $" << "\nДата поступление товара на склад: " << this->date << endl;
};


														//Showing List of Objects Names
void JustShow(Product* arrS, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "\n" << i + 1 << ".";
		cout << arrS[i].GetName();
		//arrS[i].Calculate();
		//cout << endl;
	}
}
														//function to show all object in array with details
void ShowALL(Product* arrS, int length)  
{
	
	int menu;
	int detailed = -1;
	do{
		
	for (int i = 0; i < length; i++)
	{
		
		cout << "\n" << i + 1 << ".";
		if (i == detailed - 1)
		{
			cout << "\n----------" << endl;
			arrS[i].ShowProduct();
			cout << "----------";
			continue;

		}
		cout<<arrS[i].GetName();
	}
	
	//cout << "----------------\nАвто просмотр, просмотр будет завершен в течении 10 сек\n------------------" << endl;
	//Sleep(10000);
	cout << "\n\n\n----------\n0. Для Завершение просмотра\n1. Подробная информация по элементу\n---------"<<endl;
	
		menu = InputMenu(0,2);
		if (menu == 1) {
			
			cout << "Вы перешли в режим подробного просмотра" << endl;
			cout << "Введите номер элемента: " << endl;
			detailed = Input();
		}
		system("cls");
	} while (menu != 0);
};



						//----------------------INPUT FUNCTIONS------------------------

string DataFormatInput()
{
	int day, month, year;
	string date;
	cout << "Введите Дату поступления товара на склад \n  В формате DD/MM/YY" << endl;
	cout << "День: ";
	day = InputMenu(1, 31);
	cout << "Месяц: ";
	month = InputMenu(1, 12);
	cout << "Год: ";
	year = InputMenu(2020, 2023);
	date = to_string(day) + '/' + to_string(month)+ '/' + to_string(year);
	return date;
}


string CategoryInput()
{
	string category;
	cout << "Выберите категорию товара \n 1.Продукты \n 2.Промышленные товары \n 3.Косметика" << endl;
	int in = InputMenu(1,3);
	switch (in)
	{
	case 1:
		category = "Продукты";
		break;
	case 2:
		category = "Промышленные товары";
		break;
	case 3:
		category = "Косметика";
		break;
	default:

		cout << "Вы ввели неверное значение" << endl;
		break;
	}
	return category;
}

string NameInput()
{
	string name;
	cout << "Введите имя товара" << endl;
	cin >> name;
	return name;
}

int PriceInput() 
{
	cout << "Введите Стоимость товара $" << endl;
	return Input();
}

int AmountInput() 
{
	cout << "Введите количество товаров" << endl;
	int amount = Input();
	return amount;
}

void FullEdit(Product &product) 
{
		product.SetName(NameInput());
		product.SetCategory(CategoryInput());
		product.SetDate(DataFormatInput());
		product.SetAmount(AmountInput());		
		product.SetPrice(PriceInput());

}
//-------------------------------------
double Product::Calculate() 
{
	return (this->amount) * (this->price);
}


void Product::EditField()
{
	system("cls");
	int menu;
	do {
		this->ShowProduct();
		cout << "\n-----\nВыберите поле для редактирования\n1. Имя\n2. Категория\n3. Количество\n4. Цена\n5. Дата \n6. Вывести общую стоимость товаров\n7. Завершить редактирование" << endl;
		menu = InputMenu(1, 7);
		switch (menu) {
		case 1:
			this->name= NameInput();
			break;
		case 2:
			this->category = CategoryInput();
			break;
		case 3:
			this->amount = AmountInput();
			
			break;
		case 4:
			this->price= PriceInput();
			break;
		case 5:
			this->date=DataFormatInput();
			
			break;
		case 6:
			cout << "\nОбщая стоимость указанного товара : " << this->Calculate() << " $" << endl;
			
			Sleep(6000);
			break;
		}
		system("cls");
	} while (menu != 7);
}


//-----------------------------------
Order::Order() {
	shopname = "Не задано имя";
	shopdate = "Дата не задана";
	shopamount = 0;
}


//Первыми объявлю геттеры
string Order::GetDate()
{
	return shopdate;
}
string Order::GetName()
{
	return shopname;
}
int Order::GetSAmount() {
	return shopamount;
}
 

void Order::ShowProduct()  //Функция выводит имена всех продуктов добавленых в заказ. Первостепенно релизую самые жизненно важные функции
{

	for (int i = 0; i < products.size(); i++)
	{
		cout << i + 1 << ". " << products[i].GetName() << endl;//<<"\nКоличество"<<
	}

}


void Order::EditField() // Позволяет отредактировать все поля продукта
{

	int r;
	int add;
	do {
		system("cls");
		ShowShopInfo();
		cout << "\n1. Имя\n2. Data Заказа\n0. Выход из редактора" << endl;
		r = InputMenu(0, 2);
		string ssss;
		switch (r) {
		case 1:
			cout << "Введите имя магазина: ";
			
			cin >> ssss;
			this->shopname = ssss;
			break;
		case 2:
			cout << "Введите дату заказа: ";
			cin >> ssss;
			this->shopdate = ssss;
			break;
		}
	} while (r != 0);

}



//case 3:
//	cout << "Выберите номер товара: ";
//	cin >> add;


void Order::ShowShopInfo()
{
	cout << "Информация о магазине\n---\n " << endl << "Имя Магазина: " << GetName() << "\nВсе продукты добавленные в заказ: " <<endl;


	ShowProduct();


	cout << "\n-------\nДата заказа: " << GetDate() <<"\n-----\n" << endl;



}

void ShowOrders(vector<Order> orders)
{
	for (int i = 0; i < orders.size(); i++)
	{
		cout <<i+1<<". "<< orders[i].GetName() << endl;

	}
}


void Order::PushProduct(Product foradd) 
{
	products.push_back(foradd);

}

void Order::PopProduct(Product foradd) {
	products.pop_back();
}

//Функция друг которая позволяет вывести товары для заданного магазина стоимость которых превышает 1000рублей
double Order::Calculate() 
{
	double summ= 0;
	for (int i = 0; i < products.size(); i++)
	{
		summ += products[i].GetAmount();  //<<"\nКоличество"<<
	};
	return summ;
}


const void ShowExpensive(const Order& order)
{
	for (int i = 0; i < order.products.size(); i++)
	{
		if (order.products[i].GetCPrice() > 1000)
		{
			cout << i + 1 << ". " << order.GetName() << endl
		};
		

	};
}