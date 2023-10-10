#pragma once
#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1);
	void Print()const;
	int GetMonthDay(int year, int month);
	//Date& operator=(const Date& d)
	//{
	//	if (this!=&d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;
	//}
	bool operator<(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;
	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);