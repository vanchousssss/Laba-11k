#include "Money.h"
Money::Money(void)
{
	rub = 0;
	kop = 0;
}
Money::~Money(void)
{
}
Money::Money(long M, int C)
{
	rub = M;
	kop = C;
}
Money::Money(const Money& money)
{
	rub = money.rub;
	kop = money.kop;
}
void Money::Set_kop(int C)
{
	kop = C;
}
void Money::Set_rub(long M)
{
	rub = M;

}
Money& Money::operator=(const Money& c)
{
	if (&c == this)return *this;
	rub = c.rub;
	kop = c.kop;
	return *this;
}
istream& operator>>(istream& in, Money& c)
{
	cout << "\nРублей : "; in >> c.rub;
	cout << "\nКопеек : "; in >> c.kop;
	return in;
}
ostream& operator<<(ostream& out, const Money& c)
{
	out << c.rub << ',' << c.kop;
	out << "\n";
	return out;
}
bool Money::operator <(const Money& t)
{

	if (rub < t.rub)return true;
	if (rub == t.rub && kop < t.kop)return true;
	return false;
}
bool Money::operator >(const Money& t)
{
	if (rub > t.rub)return true;
	if (rub == t.rub && kop > t.kop)return true;
	return false;
}
Money Money::operator+(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p;
}
Money Money::operator/(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 / temp2) / 100;
	p.kop = (temp1 / temp2) % 100;
	return p;
}
Money Money::operator/(const int& t)
{
	int temp1 = rub * 100 + kop;
	Money p;
	p.rub = (temp1 / t) / 100;
	p.kop = (temp1 / t) % 100;
	return p;
}
Money Money::operator*(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 * temp2) / 100;
	p.kop = (temp1 * temp2) % 100;
	return p;
}
Money Money::operator*(const int& t)
{
	int temp1 = rub * 100 + kop;
	Money p;
	p.rub = (temp1 * t) / 100;
	p.kop = (temp1 * t) % 100;
	return p;
}
