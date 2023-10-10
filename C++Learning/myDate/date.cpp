#include"date.h"

// ��ȡĳ��ĳ�µ�����
int Date::GetMonthDay(int year, int month)
{
	const static int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month==2 && ((year%4==0&&year%100!=0)||year%400==0))
	{
		return 29;
	}
	return monthArray[month];
}
// ȫȱʡ�Ĺ��캯��
Date::Date(int year , int month, int day)
	:_year(year)
	,_month(month)
	,_day(day)
{
	if (month<1||month>12
		||day<1||day>GetMonthDay(year,month))
	{
		cout << "�Ƿ�����" << endl;
	}
}
// ����+=����
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day+= day;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month==13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
// ����+����
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
// ����-����
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
// ����-=����
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// >���������
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// ==���������
bool Date::operator==(const Date& d)
{
	return _year == d._year 
		&& _month == d._month 
		&& _day == d._day;
}
// >=���������
bool Date::operator >= (const Date& d)
{
	return *this > d
		|| *this == d;
}
// <���������
bool Date::operator < (const Date& d)
{
	return !(*this>=d);
}
// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}
// ����-���� ��������
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;

	if (max < min)
	{
		max = d;
		min = *this;
	}
	int dif = 0;
	while (max != min)
	{
		min++;
		dif++;
	}
	return dif;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}


