#include <iostream>
#include <vector>
#include <ctime>
#include "Money.h"
#include <cstdlib>
using namespace std;
typedef vector<Money>Vec;
Vec make_vector(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        Money a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}
Money srednee(Vec v)
{
    Money s;
    for (int i = 0; i < v.size(); i++)
        s = s + v[i];
    int n = v.size();
    return s / n;
}
Money max(Vec v)
{
    Money m = v[0];
    int  n = 0;
    for (int i = 0; i < v.size(); i++)
        if (m < v[i])
        {
            m = v[i];
            n = i;
        }

    return m;
}
void del_vector(Vec& v, int pos)
{
    v.erase(v.begin() + pos);
}
Money min(Vec v)
{
    Money m = v[0];
    int n = 0;
    for (int i = 0; i < v.size(); i++)
        if (m > v[i])
        {
            m = v[i];
            n = i;
        }

    return m;
}
void umnozh(Vec& v)
{
    Money m = min(v);
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] * m;
}
void add_vector(Vec& v, Money& el, int pos)
{
    v.insert(v.begin() + pos, el);
}
void print_vector(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void del2(Vec& v) {
    Money sred = srednee(v);
    for (int i = 0; i < v.size(); i++)
        if (v[i] < sred) {
            v.erase(v.begin() + i);
            i--;
        }
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    try
    {
        vector<Money> v;
        vector<Money>::iterator vi = v.begin();
        int n;
        cout << "Введите количество элементов : ";
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        Money MAX = max(v);
        cout << "Позиция для вставки максимального элемента : ";
        int pos;
        cin >> pos;
        if (pos > v.size())throw 1;
        add_vector(v, MAX, pos);
        print_vector(v);
        cout << "Удалине элементов меньше среднего арифметического:" << endl;
        del2(v);
        print_vector(v);
        cout << "Умножение всех элементов на минимальный" << endl;
        umnozh(v);
        print_vector(v);
    }
    catch (int)//блок обработки ошибок
    {
        cout << "error!";
    }
}