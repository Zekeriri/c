#include<iostream>
using namespace std;
#include"RBTree.h"
int main()
{
	int a[] = { 2,4,3,1,9,0,8 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	//t.InOrder();
	cout<<t.IsBalance();
}