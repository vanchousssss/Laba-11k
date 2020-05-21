#pragma once
#include <iostream>
using namespace std;

class Money
{
	int rub;
	int kop;
public:
	Money(void);
public:
	virtual ~Money(void);
	Money(long, int);
	Money(const Money&);
	long Get_rub() { return rub; }
	int Get_kop() { return kop; }
	void Set_rub(long);
	void Set_kop(int);
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator/(const Money&);
	Money operator/(const int&);
	Money operator*(const Money&);
	Money operator*(const int&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	friend istream& operator>>(istream& in, Money& c);
	friend ostream& operator<<(ostream& out, const Money& c);
};

