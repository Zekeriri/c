#pragma once
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	// �������캯�� ��ֵ��������� ��������������д��������Ĭ�ϵľ͹���
	//Date(const Date& d);
	//Date& operator=(const Date& d);
	//~Date();
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);