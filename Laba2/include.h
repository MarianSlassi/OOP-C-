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


// ������� �������� ������ ����� � ������ ����, ��� �������� ��������������
// ���������� � ��������� ���������� �������, ��-�� ������� ����������, ����� �������� ���� ������ ���������� ���������, ��� �������� ������������� ����������

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
������� 12
���������� ����������.��������� � ������������ ���������� �������� � 
��� ����.������� ������� ����� ��������� ������ ��������� new.
���������� ������ � ��� ������� � � ��������� ������������ �����* .h.
�� ��������� ������ � �������� ���������� ���������� �������� ������ � ������� �����������.
���������� ������� � ��� ������.
������������ ���������� ����(1 �������� �������� ��������� ��������, 2 �������� ��������, 3 �����).
� ����� ��������� ��������� � �������� ����������� ������� �� ��������.
--------



-------------------------
12. ������� ��������� � ������� Product, ����������� ������� � 
������ � �������, ��������� �� ������.
����� �������� � ���� ��������� ���� � ������:
- ������������ ������;
- ��������� (��������/������������ ������/���������)
- ���������� ������ ������;
- ���� ������� ������;
- ���� ����������� ������ �� �����.
- ����������� �� ���������;
- ����������;
- ����� ��������� �������� ��������� ��������;
- ����� ��������� �������� ��������� ��������;
- ����� �������� ����� ��������� ���������� ������ (���� ������ ��� ������).
����������� ����� Order �������� ��������� ��������:
- �������� ��������-���������;
- ���� ������;
- ���������� ����������� ������;
- ����������� ����� ��������� ��������� ��������;
- �������-����, ������� ��������� ������� ������ ��� ��������� ��������, 
��������� ������� ��������� 1000 ������.

















*/
