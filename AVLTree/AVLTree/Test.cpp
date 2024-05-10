#include<iostream>
using namespace std;

#include "AVLTree.h"


int main()
{
	AVLTree<int> a;
	a.Insert(2);
	a.Insert(4);
	a.Insert(3);
	a.Insert(1);
	a.Insert(4);
	a.Insert(9);
	a.InOrder();
	return 0;
}