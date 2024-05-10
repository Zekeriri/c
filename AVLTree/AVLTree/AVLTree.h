#pragma once


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr),
		_pRight(nullptr),
		_pParent(nullptr),
		_data(data),
		_bf(0)
	{}

		AVLTreeNode<T>* _pLeft;
		AVLTreeNode<T>* _pRight;
		AVLTreeNode<T>* _pParent;
		T _data;
		int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:root(nullptr)
	{}
	bool Insert(const T& data)
	{
		PNode newNode = new Node(data);
		//1. 空节点
		if (root == nullptr)
		{
			root = newNode;
			return true;
		}

		//2. 二叉搜索树插入，调整平衡因子
		PNode cur = root;
		PNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data) cur = cur->_pLeft;
			else if (data > cur->_data) cur = cur->_pRight;
			else return false;
		}
		if (data < parent->_data) parent->_pLeft = newNode;
		else if (data > parent->_data) parent->_pRight = newNode;
		else return false;
		newNode->_pParent = parent;
		//更新_bf值
		updateBF(newNode);
		return true;
	}
	void InOrder()
	{
		_InOrder(root);
	}
private:
	void _InOrder(PNode root)
	{
		if (root == nullptr) return;
		_InOrder(root->_pLeft);
		cout << root->_data << endl;
		_InOrder(root->_pRight);
	}
	void LRotate(PNode cur)
	{
		PNode parent = cur->_pParent;
		PNode sub = cur->_pRight;
		PNode subLeft = sub->_pLeft;
		if (parent == nullptr)
		{
			sub->_pParent = nullptr;
			root = sub;
		}
		else
		{
			if (parent->_pLeft == cur) parent->_pLeft = sub;
			else parent->_pRight = sub;
			sub->_pParent = parent;
		}
		cur->_pParent = sub;
		cur->_pRight = subLeft;
		sub->_pLeft = cur;
		if (subLeft)
		{
			subLeft->_pParent = cur;
		}
	}
	void RRotate(PNode cur)
	{
		PNode parent = cur->_pParent;
		PNode sub = cur->_pLeft;
		PNode subRight = sub->_pRight;
		if (parent == nullptr)
		{
			sub->_pParent = nullptr;
			root = sub;
		}
		else
		{
			if (parent->_pLeft == cur) parent->_pLeft = sub;
			else parent->_pRight = sub;
			sub->_pParent=parent;
		}
		cur->_pParent = sub;
		cur->_pLeft = subRight;
		sub->_pRight = cur;
		if (subRight)
		{
			subRight->_pParent = cur;
		}
	}
	void updateBF(PNode cur)
	{
		PNode parent=cur->_pParent;
		if (parent == nullptr) return;

		if (parent->_pLeft == cur) parent->_bf--;
		else parent->_bf++;

		if (parent->_bf == 0) return;
		else if (parent->_bf == -1 || parent->_bf == 1) updateBF(parent);
		else if (parent->_bf == -2)
		{
			//1，左左，右单旋
			if (cur->_bf == -1) RRotate(cur->_pParent);

			//2，左右，先左后右
			if (cur->_bf == 1)
			{
				LRotate(cur);
				RRotate(cur->_pParent);
			}
		}
		else if (parent->_bf == 2)
		{
			//1，右右，左单旋
			if (cur->_bf == 1) LRotate(cur->_pParent);

			//2，右左，先右后左
			if (cur->_bf == -1)
			{
				RRotate(cur);
				LRotate(cur->_pParent);
			}
		}
		return;
	}
	PNode root;
};