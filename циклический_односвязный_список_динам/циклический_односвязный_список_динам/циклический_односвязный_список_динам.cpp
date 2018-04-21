// циклический_односвязный_список_динам.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include <string>
#include <iomanip>//setprecision
#include <limits>
#include <conio.h> 
#include <Windows.h>//для setconsoleCP
using namespace std;

int NumElements = 0;
struct node
{
	double info;
	string lee;
	struct node *next;
}*last;


class circular_llist
{
public:
	void create_node(double value, string str);
	void add_begin(double value, string str);
	void add_after(double value, string str, int position);
	void delete_element(double value);
	void search_element(double value);
	void display_list();
	circular_llist()
	{
		last = NULL;
	}
};
int IInsert(int MaxNum) {//ввод числа типа int от 1 до MaxNum
	string s;
	bool key = false;
	int res;

	do {
		getline(cin, s);
		int i;
		if (int i = s.find(' ') != std::string::npos) {
			s.resize(i + 1);
		}
		while ((i = s.find(' ')) != std::string::npos)
			s.erase(i, 1);

		size_t check;
		try {
			res = stoi(s, &check);
			if (check == s.size()) {
				if ((res >= 1) && (res <= MaxNum))
				{
					key = true;
				}
				else
				{
					cout << "Вне диапазона количества элементов" << endl;
				}
			}
			else {
				cout << "Ошибка ввода" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "Введено не число" << endl; cout << "Попробуйте снова" << endl; }
		catch (const out_of_range&) {
			cout << "Число вне диапазона integer" << endl; cout << "Попробуйте снова" << endl;
		}
	} while (key == false);
	return res;
}
double DInsert() {
	string s;
	bool key = false;
	double res;
	system("cls");
	cout << "Введите число: ";
	/*getline(cin, s);*/
	do {

		getline(cin, s);
		int i;
		if (int i = s.find(' ') != std::string::npos) {
			s.resize(i + 1);
		}
		while ((i = s.find(' ')) != std::string::npos)
			s.erase(i, 1);

		size_t check;
		try {
			res = stod(s, &check);
			if (check == s.size()) {
				key = true;
			}
			else {
				cout << "Ошибка ввода" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "Введено не число" << endl; cout << "Попробуйте снова" << endl; }
		catch (const out_of_range&) {
			cout << "Число вне диапазона double" << endl; cout << "Попробуйте снова" << endl;
		}
	} while (key != true);
	return res;
}

int main()
{
	cout << setprecision(100);
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	double element;
	int  position;
	string ch;
	int choice;
	circular_llist cl;
	cout << "\t Циклический односвязный список\n";
	while (1)
	{
		cout << "1.Добавить элемент\n";
		cout << "2.Добавить в наало\n";
		cout << "3.Добавить после\n";
		cout << "4.Удалить\n";
		cout << "5.Поиск\n";
		cout << "6.Показать\n";
		cout << "7.Выход\n";
		cout << "Выберите действие: ";
		choice = IInsert(7);
		switch (choice)
		{
		case 1:
			element = DInsert();
			cout << "Введите строку: ";
			getline(cin, ch);
			cl.create_node(element, ch);
			break;
		case 2:
			if (last == NULL)
			{
				cout << "Сначала создайте список" << endl;
			}
			else {
				element = DInsert();
				cout << "Введите строку: ";
				getline(cin, ch);
				cl.add_begin(element, ch);
			}
			break;
		case 3:
			if (last == NULL)
			{
				cout << "Сначала создайте список" << endl;
			}
			else {
				element = DInsert();
				cout << "Введите строку: ";
				getline(cin, ch);
				cout << "Введите номер позиции после которой добавить число(от 1 до " << NumElements << "): ";
				position = IInsert(NumElements);
				cl.add_after(element, ch, position);
			}
			break;
		case 4:
			system("cls");
			if (last == NULL)
			{
				cout << "Список пуст" << endl;
				break;
			}
			element = DInsert();
			cl.delete_element(element);
			break;
		case 5:
			system("cls");
			if (last == NULL)
			{
				cout << "Список пуст" << endl;
				break;
			}
			element = DInsert();
			cl.search_element(element);
			break;
		case 6:
			system("cls");
			cl.display_list();
			break;
		case 7:
			exit(1);
			break;
		default:
			cout << "Некорректное значение" << endl;
		}
	}
	return 0;
}
void circular_llist::create_node(double value, string str)
{
	struct node *temp;
	/*temp = (node*)malloc(0);*/
	/*temp = (node*)realloc(temp,sizeof(node));*/
	temp = new(struct node);
	temp->info = value;
	temp->lee = str;
	if (last == NULL)
	{
		last = temp;
		temp->next = last;
	}
	else
	{
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
	NumElements++;
}
void circular_llist::add_begin(double value, string str)
{

	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->lee = str;
	temp->next = last->next;
	last->next = temp;
	NumElements++;
}
void circular_llist::add_after(double value, string str, int pos)
{
	struct node *temp, *s;
	s = last->next;
	for (int i = 0; i < pos - 1; i++)
	{
		s = s->next;
		if (s == last->next)
		{
			cout << "There are less than ";//при правильной работе программы доп проверка не должна использоваться
			cout << pos << " in the list" << endl;
			return;
		}
	}
	temp = new(struct node);
	temp->next = s->next;
	temp->info = value;
	temp->lee = str;
	s->next = temp;
	if (s == last)
	{
		last = temp;
	}
	NumElements++;
}
void circular_llist::delete_element(double value)
{
	struct node *temp, *s;
	s = last->next;
	if (last->next == last && last->info == value)
	{
		temp = last;
		last = NULL;
		delete(temp);
		NumElements--;
		return;
	}
	if (s->info == value)
	{
		temp = s;
		last->next = s->next;
		delete(temp);
		NumElements--;
		return;
	}
	while (s->next != last)
	{

		if (s->next->info == value)
		{
			temp = s->next;
			s->next = temp->next;
			delete(temp);
			cout << "Элемент " << value;
			cout << " удалён" << endl;
			NumElements--;
			return;
		}
		s = s->next;
	}
	if (s->next->info == value)
	{
		temp = s->next;
		s->next = last->next;
		delete(temp);
		last = s;
		NumElements--;
		return;
	}
	cout << "Элемент " << value << " не найден" << endl;
}
void circular_llist::search_element(double value)
{
	struct node *s;
	int counter = 0;
	s = last->next;
	while (s != last)
	{
		counter++;
		if (s->info == value)
		{
			cout << "Элемент " << value;
			cout << " находится на позиции " << counter << endl;
			return;
		}
		s = s->next;
	}
	if (s->info == value)
	{
		counter++;
		cout << "Элемент " << value;
		cout << " находится на позиции " << counter << endl;
		return;
	}
	cout << "Элемент " << value << " не найден" << endl;
}
void circular_llist::display_list()
{
	struct node *s;
	if (last == NULL)
	{
		cout << "Список пуст" << endl;
		return;
	}
	s = last->next;
	cout << "Список: " << endl;
	while (s != last)
	{
		cout << s->info << "  " << s->lee << "->";
		s = s->next;
	}
	cout << s->info << "  ";
	cout << s->lee << endl;
}
