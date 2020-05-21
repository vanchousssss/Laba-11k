#include "Money.h"
#include "Mnvo.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите 5 элементов " << endl;
	Vector<Money>vec(5);
	vec.Print();
	Money p = vec.Max();
	cout << "Максимальный элемент = " << p << endl;
	cout << "Позиция для вставки : ";
	int pos;
	cin >> pos;
	vec.Add(p, pos);
	vec.Print();
	cout << "Удаление элементов меньше среднего арифметического " << endl;
	vec.Del();
	vec.Print();
	cout << "Умножение всех элементов на минимальный элемент " << endl;
	vec.Umnozh();
	vec.Print();
}