
#include"binary_tree.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(const BTDataType* a, int* pi)
{
	if (a[*pi] == '#') return NULL;
	BTNode* root = BuyNode(a[*pi]);
	(*pi)++;
	root->left=BinaryTreeCreate(a, pi);
	(*pi)++;
	root->right = BinaryTreeCreate(a, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return BinaryTreeLevelKSize(root->left,k-1) + BinaryTreeLevelKSize(root->right,k-1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL) return NULL;
	if (root->data == x) return root;
	BTNode* find = NULL;
	find = BinaryTreeFind(root->left,x);
	if (find) return find;
	find = BinaryTreeFind(root->right,x);
	if (find) return find;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL) return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreePrevOrder(root->left);
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	std::queue<BTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		if (root == NULL) continue;
		printf("%c ", root->data);
		q.push(root->left);
		q.push(root->right);
	}
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	std::queue<BTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		if (root == NULL && !q.empty())
		{
			while (!q.empty())
			{
				root = q.front();
				q.pop();
				if (root) return false;
			}
			return true;
		}
		q.push(root->left);
		q.push(root->right);
	}
	return true;
}
