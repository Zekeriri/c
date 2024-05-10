
#include"binary_tree.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return BinaryTreeLevelKSize(root->left,k-1) + BinaryTreeLevelKSize(root->right,k-1);
}
// 二叉树查找值为x的节点
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
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL) return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreePrevOrder(root->left);
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL) return;
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->data);
}
// 层序遍历
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
// 判断二叉树是否是完全二叉树
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
