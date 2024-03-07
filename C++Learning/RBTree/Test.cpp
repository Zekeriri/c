#include<iostream>
#include<vector>
using namespace std;

#include "RBTree.h"

//int main()
//{
//	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	//t.InOrder();
//	cout << t.IsBalance() << endl;
//	return 0;
//}

int main()
{
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}
	RBTree<int, int> t;
	size_t begin = clock();
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end = clock();

	size_t begin_f = clock();
	for (auto e : v)
	{
		t.Find(e);
	}

	for (size_t i = 0; i < N; i++)
	{
		t.Find(rand() + i);
	}
	size_t end_f = clock();
	cout << "Time:" << end - begin << endl;
	cout << "is balance:"<<t.IsBalance() << endl;
	cout << "height:"<<t.Height() << endl;
	cout << "size:"<<t.Size() << endl;
	cout << "Find time:" << end_f - begin_f << endl;


}