#include<iostream>
using namespace std;
#include "vector.h"

namespace dl
{
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		v.insert(v.begin(),2.5);
		vector<int>::iterator it = v.begin();
		auto pos = v.begin()+4;
		v.erase(pos);
		for (auto e : v)
		{
			cout << e << " ";
		}
	}
	void test_vector2()
	{
		vector<int*> v1;
		v1.resize(10);
		vector<string> v2;
		v2.resize(10);
	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		vector<int>::reverse_iterator it = v.rbegin();
		while (it != v.rend())
		{
			cout << *it << " ";
			++it;
		}
	}
}

int main()
{
	dl::test_vector3();
	return 0;
}