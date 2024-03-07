#include<iostream>
#include<string>
#include<vector>
using namespace std;

#include"Stack.h"
#include"PriorityQueue.h"

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

void test_priority_queue()
{
	dl::priority_queue<int, vector<int>,Greater<int>> q;
	q.push(3);
	q.push(1);
	q.push(5);
	q.push(4);

	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
		cout << endl;
	}
}

template<class T1,class T2>
class Data
{
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int,double>
{
public:
	Data() { cout << "Data<int,double>" << endl; }
private:
};

// Æ«ÌØ»¯
template<class T1>
class Data<T1, double>
{
public:
	Data() { cout << "Data<T1,double" << endl; }
};


template<class T1, class T2>
class Data<T1*,T2*>
{
public:
	Data() { cout << "Data<T1*,T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
int main()
{
	//test_priority_queue();
	/*Less<int> less;
	cout << less(2, 3);*/
	Data<double*, double*> d1;
	return 0;
}