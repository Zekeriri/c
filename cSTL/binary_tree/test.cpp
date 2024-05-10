#include "binary_tree.h"

BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	//	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	//	node2->right = node7;
	node4->left = node5;
	node4->right = node6;
	return node1;
}


void test2()
{
	const char* a = "ABD##E#H##CF##G##";
	//const char* a = "AB##C##";
	int i = 0;
	BTNode* bt2 = BinaryTreeCreate(a, &i);
	//BinaryTreeLevelOrder(bt2);
	//BinaryTreePrevOrder(bt2);
	//BinaryTreeInOrder(bt2);
	//BinaryTreePostOrder(bt2);
	//std::cout<<BinaryTreeComplete(bt2);
	//std::cout << BinaryTreeSize(bt2);
	//std::cout << BinaryTreeLeafSize(bt2);
	
	//std::cout << BinaryTreeLevelKSize(bt2,3);
	std::cout << BinaryTreeFind(bt2, 'B');
	BinaryTreeDestory(bt2);
}

int main()
{
	//test1();
	test2();
	return 0;
}