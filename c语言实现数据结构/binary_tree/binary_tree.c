#include "binary_tree.h"
#include "queue.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* node = BuyNode(a[*pi]);
	(*pi)++;
	node->left = BinaryTreeCreate(a, pi);
	node->right = BinaryTreeCreate(a, pi);
	return node;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root==NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (!(root->left || root->right))
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q,root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		if (node->left)
		{
			QueuePush(&q, node->left);
		}
		if (node->right)
		{
			QueuePush(&q, node->right);
		}
		printf("%d ", node->data);
		QueuePop(&q);
	}
	printf("\n");
	BinaryTreeDestory(&q);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		if (node->left)
		{
			QueuePush(&q, node->left);
		}
		else
		{
			break;
		}
		if (node->right)
		{
			QueuePush(&q, node->right);
		}
		else
		{
			break;
		}
		QueuePop(&q);
	}
	if (QueueEmpty(&q))
	{
		QueueDestroy(&q);
		return 1;
	}
	else
	{
		while (!QueueEmpty(&q))
		{
			BTNode* node = QueueFront(&q);
			if (node->left && node->right)
			{
				QueueDestroy(&q);
				return 0;
			}
			QueuePop(&q);
		}
		QueueDestroy(&q);
		return 1;
	}
}