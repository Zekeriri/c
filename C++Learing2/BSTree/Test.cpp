#include"BSTree.h"

int main()
{
	BSTree<int> bs;
	bs.InsertR(2);
	bs.Insert(4);
	bs.Insert(3);
	bs.Insert(1);
	bs.Insert(4);
	bs.Insert(9);
	bs.EraseR(3);
	bs.InOrder();
	return 0;
}