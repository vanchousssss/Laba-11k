#include "Money.h"
#include "Mnvo.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "������� 5 ��������� " << endl;
	Vector<Money>vec(5);
	vec.Print();
	Money p = vec.Max();
	cout << "������������ ������� = " << p << endl;
	cout << "������� ��� ������� : ";
	int pos;
	cin >> pos;
	vec.Add(p, pos);
	vec.Print();
	cout << "�������� ��������� ������ �������� ��������������� " << endl;
	vec.Del();
	vec.Print();
	cout << "��������� ���� ��������� �� ����������� ������� " << endl;
	vec.Umnozh();
	vec.Print();
}