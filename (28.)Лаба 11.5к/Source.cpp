#include <iostream>
#include "Money.h"
#include "Mnvo.h"
#include <vector>
#include <stack>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Vector<Money>v(5);
	v.Print();
	Money t = v.Max();
	cout << "\n������������ ������� = " << t << endl;
	cout << "������� ��� ������� : ";
	int pos;
	cin >> pos;
	v.Add(t, pos);
	v.Print();
	cout << "������� �������������� = " << v.Srednee() << endl;
	cout << "�������� ��������� ������ �������� ��������������� : " << endl;
	v.Del();
	v.Print();
	cout << "��������� �� ����������� �������" << endl;
	v.Umnozh();
	v.Print();

}