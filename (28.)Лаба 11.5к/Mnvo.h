#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class T> class Vector
{
	stack <T> s;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void Print();
	T Srednee();
	void Add(T el, int pos);
	T Max();
	T Del();
	T Min();
	void Umnozh();
};
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
}
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	vector<T> v;
	len = v.len;
	vector v = copy_stack_to_vector(Vec.s);
	s = copy_vector_to_stack(v);
}
template <class T>
void Vector<T>::Print()
{
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Srednee()
{
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;
	T sum = s.top();
	s.pop();
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}
	s = copy_vector_to_stack(v);
	return sum / n;
}
template <class T>
void Vector<T>::Add(T el, int pos)
{
	vector <T>v;
	T t;
	int i = 1;
	while (!s.empty())
	{
		t = s.top();
		if (i == pos)v.push_back(el);
		v.push_back(t);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Max()
{
	T m = s.top();

	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
T Vector<T>::Del()
{

	T m = Srednee();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		//если t не равен максимальному, то добавить его в вектор 
		if (t > m)v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
void Vector<T>::Umnozh()
{
	T m = Min();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top(); v.push_back(t * m);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
