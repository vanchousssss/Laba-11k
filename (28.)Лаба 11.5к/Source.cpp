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
	cout << "\nМаксимальный элемент = " << t << endl;
	cout << "Позиция для вставки : ";
	int pos;
	cin >> pos;
	v.Add(t, pos);
	v.Print();
	cout << "Среднее арифметическое = " << v.Srednee() << endl;
	cout << "Удаление элементов меньше среднего арифметического : " << endl;
	v.Del();
	v.Print();
	cout << "Умножение на минимальный элемент" << endl;
	v.Umnozh();
	v.Print();

}