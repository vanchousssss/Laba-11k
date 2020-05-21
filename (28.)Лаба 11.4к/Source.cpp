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
	V v = copy_stack_to_vector(s);//�������� ���� � ������
	int n = 1;
	Money sum = s.top();//��������� ����������� ����� 
	s.pop();//������� ������ ������� �� ������� 
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//�������� � ����� ������� �� ������� ����� 
		s.pop();//������� �������
		n++;
	}
	s = copy_vector_to_stack(v);//����������� ������ � ����
	return sum / n; //������� ������� ��������������
}
void Add_to_stack(S& s, Money el, int pos)
{
	V v;
	Money m;
	int i = 1;//����� �������� � �����
	while (!s.empty())//���� ���� �� ������
	{
		m = s.top();//�������� ������� �� �������
		//���� ����� ����� ������ �������, �� ������ �������� ������� 
		if (i == pos)v.push_back(el);//�������� ����� ������� � ������ 
		v.push_back(m);//�������� ������� �� ����� � ������
		s.pop();//������� ������� �� �����
		i++;
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
Money Max(S s)
{
	Money m = s.top();//���������� m ����������� �������� �� ������� �����
	V v = copy_stack_to_vector(s);//�������� ���� � ������ 
	while (!s.empty())//���� ��� �� ������
	{
		if (s.top() > m)m = s.top();//��������� m � ������ � ������� ����� 
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//������� ������ � ����
	return m; //���������� m
}
void Delete_from_stack(S& s)
{
	Money m = Srednee(s);//������� ������������ ������� 
	V v;
	Money t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� ������� �����
		//���� �� �� ����� �������������, ������� ������� � ������ 
		if (t > m)v.push_back(t);
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
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
	Money m = Min(s);//������� ����������� �������
	V v;
	Money t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� �������
		v.push_back(t * m);//����� t �� ����������� � ��������� � ������ 
		s.pop();//������� ������� �� �������
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

int main() {
	setlocale(LC_ALL, "ru");
	Money m;
	S s;
	int	n;
	cout << "���-�� ��������� ����� : ";
	cin >> n;
	s = make_stack(n);//������� ���� 
	print_stack(s);//������ �����
	m = Max(s);//��������� ������� 
	cout << "������������ ������� = " << Max(s) << endl;
	cout << "������� ��� ������� : ";
	int pos;
	cin >> pos;//������ ������� ��� ����������
	Add_to_stack(s, m, pos);//���������� ��������
	print_stack(s);//������ �����
	cout << "�������� ��������� ������ �������� ��������������� : " << endl;
	Delete_from_stack(s);
	print_stack(s);
	cout << "��������� : " << endl;
	Umnozh(s);
	print_stack(s);
}