#include"Date.h"

Date::Date(int year, int month, int day)
	:_year(year)
	,_month(month)
	,_day(day)
{
	// 检查日期是否合法
	if (month < 1 || month>12
		|| day<1 || day>GetMonthDay(year, month))
	{
		cout << "非法日期" << endl;
		return;
	}
}
void Date::Print()const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}
int Date::GetMonthDay(int year, int month)
{
	const static int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2
		&& (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 29;
	}
	return monthArray[month];
}
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day<0)
	{
		return *this += (-day);
	}
	_day -= day;

	while (_day<=0)
	{
		--_month; 
		if (_month==0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min<max)
	{
		++min;
		++n;
	}
	return n * flag;
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