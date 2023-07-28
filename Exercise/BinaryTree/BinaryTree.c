#include"BinaryTree.h"
#include"Queue.h"
#include"Queue.h"
#include<stdio.h>
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = BuyNode(a[*pi]);
	(*pi)++;
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL
		&& root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left)
		+ BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (root == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1)
		+ BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
	{
		return root;
	}
	
	BTNode* ret1 = BTreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = BTreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		pritf("N ");
		return;
	}
	printf("%d", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		pritf("N ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	printf("%d", root->data);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		pritf("N ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%d", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//������Ľڵ���û�зǿ�
	//�зǿգ�������ȫ������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}