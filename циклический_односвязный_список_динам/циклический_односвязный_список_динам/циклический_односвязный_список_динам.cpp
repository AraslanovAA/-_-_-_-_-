// �����������_�����������_������_�����.cpp: ���������� ����� ����� ��� ����������� ����������.
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
#include <Windows.h>//��� setconsoleCP
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
int IInsert(int MaxNum) {//���� ����� ���� int �� 1 �� MaxNum
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
					cout << "��� ��������� ���������� ���������" << endl;
				}
			}
			else {
				cout << "������ �����" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "������� �� �����" << endl; cout << "���������� �����" << endl; }
		catch (const out_of_range&) {
			cout << "����� ��� ��������� integer" << endl; cout << "���������� �����" << endl;
		}
	} while (key == false);
	return res;
}
double DInsert() {
	string s;
	bool key = false;
	double res;
	system("cls");
	cout << "������� �����: ";
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
				cout << "������ �����" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "������� �� �����" << endl; cout << "���������� �����" << endl; }
		catch (const out_of_range&) {
			cout << "����� ��� ��������� double" << endl; cout << "���������� �����" << endl;
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
	cout << "\t ����������� ����������� ������\n";
	while (1)
	{
		cout << "1.�������� �������\n";
		cout << "2.�������� � �����\n";
		cout << "3.�������� �����\n";
		cout << "4.�������\n";
		cout << "5.�����\n";
		cout << "6.��������\n";
		cout << "7.�����\n";
		cout << "�������� ��������: ";
		choice = IInsert(7);
		switch (choice)
		{
		case 1:
			element = DInsert();
			cout << "������� ������: ";
			getline(cin, ch);
			cl.create_node(element, ch);
			break;
		case 2:
			if (last == NULL)
			{
				cout << "������� �������� ������" << endl;
			}
			else {
				element = DInsert();
				cout << "������� ������: ";
				getline(cin, ch);
				cl.add_begin(element, ch);
			}
			break;
		case 3:
			if (last == NULL)
			{
				cout << "������� �������� ������" << endl;
			}
			else {
				element = DInsert();
				cout << "������� ������: ";
				getline(cin, ch);
				cout << "������� ����� ������� ����� ������� �������� �����(�� 1 �� " << NumElements << "): ";
				position = IInsert(NumElements);
				cl.add_after(element, ch, position);
			}
			break;
		case 4:
			system("cls");
			if (last == NULL)
			{
				cout << "������ ����" << endl;
				break;
			}
			element = DInsert();
			cl.delete_element(element);
			break;
		case 5:
			system("cls");
			if (last == NULL)
			{
				cout << "������ ����" << endl;
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
			cout << "������������ ��������" << endl;
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
			cout << "There are less than ";//��� ���������� ������ ��������� ��� �������� �� ������ ��������������
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
			cout << "������� " << value;
			cout << " �����" << endl;
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
	cout << "������� " << value << " �� ������" << endl;
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
			cout << "������� " << value;
			cout << " ��������� �� ������� " << counter << endl;
			return;
		}
		s = s->next;
	}
	if (s->info == value)
	{
		counter++;
		cout << "������� " << value;
		cout << " ��������� �� ������� " << counter << endl;
		return;
	}
	cout << "������� " << value << " �� ������" << endl;
}
void circular_llist::display_list()
{
	struct node *s;
	if (last == NULL)
	{
		cout << "������ ����" << endl;
		return;
	}
	s = last->next;
	cout << "������: " << endl;
	while (s != last)
	{
		cout << s->info << "  " << s->lee << "->";
		s = s->next;
	}
	cout << s->info << "  ";
	cout << s->lee << endl;
}
