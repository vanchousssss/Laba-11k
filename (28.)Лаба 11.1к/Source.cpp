#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef vector<float>Vec;
//функция для формирования вектора 
Vec make_vector(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        float a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}
//среднее арифметическое
float srednee(Vec v)
{
    float s = 0;
    for (int i = 0; i < v.size(); i++)
        s += v[i];
    float n = v.size();
    return s / n;
}
//поиск максимального элемента
float max(Vec v)
{

    float m = v[0],
        n = 0;
    for (int i = 0; i < v.size(); i++)
        if (m < v[i])
        {
            m = v[i];
            n = i;
        }

    return m;
}
//удалить элемент из позиции pos 
void del_vector(Vec& v, int pos)
{
    v.erase(v.begin() + pos);
}
//поиск минимального элемента 
float min(Vec v)
{
    float m = v[0],
        n = 0;
    for (int i = 0; i < v.size(); i++)
        if (m > v[i])
        {
            m = v[i];
            n = i;
        }

    return n;
}
//умножение всех элементов на минимальный
void umnozh(Vec& v)
{
    float m = min(v);
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] * v[m];
}
//добавление на позицию
void add_vector(Vec& v, float el, int pos)
{
    //добавляем на место pos элемент el 
    v.insert(v.begin() + pos, el);
}
//функция для печати вектора
void print_vector(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void del2(Vec& v) {
    float sred = srednee(v);
    for (int i = 0; i < v.size(); i++)
        if (v[i] < sred) {
            v.erase(v.begin() + i);
            i--;
        }
}
//основная функция 
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    try
    {
        vector<float> v;
        vector<float>::iterator vi = v.begin();
        int n;
        cout << "Введите количество элементов : ";
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        float MAX = max(v);
        cout << "Позиция для вставки максимального элемента : ";
        int pos;
        cin >> pos;
        if (pos > v.size())throw 1;
        add_vector(v, MAX, pos);
        print_vector(v);
        cout << "Среднее арифметическое = " << srednee(v) << endl;
        cout << "Удаление элементов меньше среднего арифметичекского " << endl;
        del2(v);
        print_vector(v);
        cout << "Умножение всех элементов на минимальный элемент " << endl;
        umnozh(v);//
        print_vector(v);
    }
    catch (int)//блок обработки ошибок
    {
        cout << "error!";
    }
}