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

void test1()
{
	BTNode* bt1 = CreateBinaryTree();
	BinaryTreePrevOrder(bt1);
	printf("\n");
	BinaryTreeInOrder(bt1);
	printf("\n");
	BinaryTreePostOrder(bt1);
	printf("\n");
	printf("%d\n", BinaryTreeSize(bt1));
	printf("%d\n", BinaryTreeLeafSize(bt1));
	printf("%d\n", BinaryTreeLevelKSize(bt1, 3));
	printf("%p\n", BinaryTreeFind(bt1, 3));
	BinaryTreeLevelOrder(bt1);
	printf("%d ", BinaryTreeComplete(bt1));
	BinaryTreeDestory(bt1);
}

void test2()
{
	char* a = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* bt2 = BinaryTreeCreate(a,&i);
	BinaryTreePrevOrder(bt2);
}

int main()
{
	//test1();
	test2();
	return 0;
}