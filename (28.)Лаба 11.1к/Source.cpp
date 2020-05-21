#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef vector<float>Vec;
//������� ��� ������������ ������� 
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
//������� ��������������
float srednee(Vec v)
{
    float s = 0;
    for (int i = 0; i < v.size(); i++)
        s += v[i];
    float n = v.size();
    return s / n;
}
//����� ������������� ��������
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
//������� ������� �� ������� pos 
void del_vector(Vec& v, int pos)
{
    v.erase(v.begin() + pos);
}
//����� ������������ �������� 
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
//��������� ���� ��������� �� �����������
void umnozh(Vec& v)
{
    float m = min(v);
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] * v[m];
}
//���������� �� �������
void add_vector(Vec& v, float el, int pos)
{
    //��������� �� ����� pos ������� el 
    v.insert(v.begin() + pos, el);
}
//������� ��� ������ �������
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
//�������� ������� 
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    try
    {
        vector<float> v;
        vector<float>::iterator vi = v.begin();
        int n;
        cout << "������� ���������� ��������� : ";
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        float MAX = max(v);
        cout << "������� ��� ������� ������������� �������� : ";
        int pos;
        cin >> pos;
        if (pos > v.size())throw 1;
        add_vector(v, MAX, pos);
        print_vector(v);
        cout << "������� �������������� = " << srednee(v) << endl;
        cout << "�������� ��������� ������ �������� ���������������� " << endl;
        del2(v);
        print_vector(v);
        cout << "��������� ���� ��������� �� ����������� ������� " << endl;
        umnozh(v);//
        print_vector(v);
    }
    catch (int)//���� ��������� ������
    {
        cout << "error!";
    }
}