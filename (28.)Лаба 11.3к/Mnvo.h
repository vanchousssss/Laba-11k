#pragma once
#include <vector>
#include <iostream> 
using namespace std;
template<class T> class Vector
{
    vector <T> v;
    float len;
public:
    Vector(void);
    Vector(int n);
    void Print();
    ~Vector(void);
    T Srednee();//вычисление среднего арифметического
    void Add(T el, int pos);//добавление элемента el на позицию pos
    T Max();//найти номер максимальнго элемента
    T Del();//удалить элементы
    float Min();//найти номер минимальнго элемента 
    void Umnozh();//умножение на минимальный
};
template<class T>
T Vector<T>::Srednee()
{
    T s = v[0];
    for (int i = 1; i < v.size(); i++)
        s = s + v[i];
    int n = v.size();
    return s / n;
}
template<class T>
void Vector<T>::Add(T el, int pos)
{
    v.insert(v.begin() + pos, el);
}
template <class T>
Vector<T>::Vector()
{
    len = 0;

}
template <class T>
Vector<T>::~Vector(void)

{
}
template <class T>
Vector<T>::Vector(int n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a; v.push_back(a);
    }
    len = v.size();
}
template <class  T>
void Vector<T>::Print()
{

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}
template <class T>
T Vector<T>::Max()
{
    T m = v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++)
        if (v[i] > m)
        {
            m = v[i]; n = i;
        }
    return m;
}
template<class T>
T Vector<T>::Del() {
    T m = v[0];
    T sred = Srednee();
    for (int i = 0; i < v.size(); i++)
        if (v[i] < sred) {
            v.erase(v.begin() + i);
            i--;
        }
    return m;
}
template<class T>
float Vector<T>::Min()
{
    T m = v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++) if (v[i] < m)
    {
        m = v[i]; n = i;
    }
    return n;
}
template<class T>
void Vector<T>::Umnozh()
{
    int m = Min(); T min = v[m];
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] * min;
}