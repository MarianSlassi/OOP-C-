#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;


class Product 
{
private:
	string name ;
	string category;
	int amount ;
	double price ;
	string date;
public:
	Product();
	~Product();
	Product(string name, string category, int amount, double price, string date);
	void SetName(string name);
	void SetCategory(string category);
	void SetDate(string date);
	void SetAmount(int amout);
	void SetPrice(double price);
	virtual void ShowProduct();
	virtual string GetName();
	string GetCategory();
	virtual string GetDate();
	int GetAmount();
	double GetPrice();
	double const GetCPrice();
	virtual void EditField();
	virtual double Calculate();
};

double const Product::GetCPrice() {
	return price;
}


// Помещаю описание класса ордер в этотже файл, для удобства редактирования
// Столкнулся с проблемой реализации задания, из-за неявных требований, далее продумал свою логику реализации программы, для удобства практического применения

class Order : public Product
{
private:
	string shopname;
	string shopdate;
	int shopamount;
	vector<Product> products;
public:
	Order();
	 void ShowProduct() override;
	 void EditField() override;
	 string GetName() override;
	 string GetDate() override;
	 void ShowShopInfo();
	 void PushProduct(Product foradd);
	 void PopProduct(Product foradd);
	 int GetSAmount();
	 double Calculate() override;
	 friend void ShowExpensive( Order order);
	 Product GetProduct(int i);
	 int SizeOfList();

};

Product Order::GetProduct(int i)
{
	return this->products[i];
}
int Order::SizeOfList()
{
	return this->products.size();
 }



/*
Вариант 12
консольное приложение.запросить у пользователя количество объектов и 
его поля.создать объекты через выделение памяти операцией new.
объявления класса и его методов – в отдельном заголовочном файле* .h.
по окончании работы с массивом освободить занимаемую массивом память с помощью деструктора.
реализация методов – вне класса.
организовать простейшее меню(1 просмотр текущего состояния объектов, 2 создание объектов, 3 выход).
в шапку программы поместить в качестве комментария задание по варианту.
--------



-------------------------
12. Создать программу с классом Product, порождающий объекты – 
данные о товарах, имеющихся на складе.
Класс включает в себя следующие поля и методы:
- наименование товара;
- категория (продукты/промышленные товары/косметика)
- количество единиц товара;
- цену единицы товара;
- дату поступления товара на склад.
- конструктор по умолчанию;
- деструктор;
- метод установки текущего состояния объектов;
- метод просмотра текущего состояния объектов;
- метод подсчёта общей стоимости указанного товара (тело метода вне класса).
Производный класс Order содержит следующие элементы:
- название магазина-заказчика;
- дата заказа;
- количество заказанного товара;
- виртуальный метод просмотра состояния объектов;
- функция-друг, которая позволяет вывести товары для заданного магазина, 
стоимость которых превышает 1000 рублей.

















*/
