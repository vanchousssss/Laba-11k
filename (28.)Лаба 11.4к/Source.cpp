#include "Money.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Money>S;
typedef vector<Money>V;
S make_stack(int n)
{
	S s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}
void print_stack(S s) {
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}
V copy_stack_to_vector(S s)
{
	V v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
S copy_vector_to_stack(V v)
{
	S s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
Money Srednee(S s)
{
	V v = copy_stack_to_vector(s);//копируем стек в вектор
	int n = 1;
	Money sum = s.top();//начальное значениедля суммы 
	s.pop();//удалить первый элемент из вектора 
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавить в сумму элемент из вершины стека 
		s.pop();//удалить элемент
		n++;
	}
	s = copy_vector_to_stack(v);//скопировать вектор в стек
	return sum / n; //вернуть среднее арифметическое
}
void Add_to_stack(S& s, Money el, int pos)
{
	V v;
	Money m;
	int i = 1;//номер элемента в стеке
	while (!s.empty())//пока стек не пустой
	{
		m = s.top();//получить элемент из вершины
		//если номер равен номеру позиции, на котоую добвляем элемент 
		if (i == pos)v.push_back(el);//добавить новый элемент в вектор 
		v.push_back(m);//добавить элемент из стека в вектор
		s.pop();//удалить элемент из стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
Money Max(S s)
{
	Money m = s.top();//переменной m присваиваем значение из вершины стека
	V v = copy_stack_to_vector(s);//копируем стек в вектор 
	while (!s.empty())//пока стк не пустой
	{
		if (s.top() > m)m = s.top();//срвниваем m и элемнт в вершине стека 
		s.pop();//удаляем элемент из стека
	}
	s = copy_vector_to_stack(v);//копиуем вектор в стек
	return m; //возвращаем m
}
void Delete_from_stack(S& s)
{
	Money m = Srednee(s);//находим максимальный элемент 
	V v;
	Money t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получаем элемент из вершины стека
		//если он не равен максимальному, заносим элемент в вектор 
		if (t > m)v.push_back(t);
		s.pop();//удаляем элемент из стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
Money Min(S s)
{
	Money m = s.top();
	V v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
void Umnozh(S& s)
{
	Money m = Min(s);//находим минимальный элемент
	V v;
	Money t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получаем элемент из вершины
		v.push_back(t * m);//делим t на минимальный и добавляем в вектор 
		s.pop();//удаляем элемент из вершины
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

int main() {
	setlocale(LC_ALL, "ru");
	Money m;
	S s;
	int	n;
	cout << "Кол-во элементов стека : ";
	cin >> n;
	s = make_stack(n);//создать стек 
	print_stack(s);//печать стека
	m = Max(s);//вычисляем среднее 
	cout << "Максимальный элемент = " << Max(s) << endl;
	cout << "Позиция для вставки : ";
	int pos;
	cin >> pos;//вводим позицию для добавления
	Add_to_stack(s, m, pos);//добавление элемента
	print_stack(s);//печать стека
	cout << "Удаление элементов меньше среднего арифметического : " << endl;
	Delete_from_stack(s);
	print_stack(s);
	cout << "Умножение : " << endl;
	Umnozh(s);
	print_stack(s);
}