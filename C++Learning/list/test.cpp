#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
#include"list.h"
void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	list<int>::iterator it = lt.begin();
	//while (it!=lt.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	lt.reverse();
	lt.sort();
	lt.unique();
	lt.sort(greater<int>());

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{

}

namespace dl
{
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		list<int> lt1(lt);

		list<int>::iterator it = lt.begin();
		for (auto e : lt)
		{
			cout << e<<" ";
		}
		cout << endl;
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void func(const list<int>& lt)
	{
		list<int>::const_reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		list<int>::const_iterator it = lt.begin();
		while (it!=lt.end())
		{
			cout << *it<<" ";
			++it;
		}
		//func(lt);
	}

}
int main()
{
	dl::test_list4();
}