#pragma once
#include<iostream>
using namespace std;

template<class T>
struct BSTnode
{
	BSTnode(const T& data=T())
		:_left(nullptr),
		_right(nullptr),
		_data(data)
	{}
	BSTnode* _left;
	BSTnode* _right;
	T _data;
};

template<class T>
struct BSTree
{
	typedef BSTnode<T> Node;
	typedef BSTnode<T>* PNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree()
	{};
	PNode Find(const T& data)
	{
		PNode cur = _pRoot;
		while (cur)
		{
			if (cur->_data > data)
			{
				cur = cur->_left;
			}
			else if (cur->_data<data)
			{
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}
		return cur;
	}
	bool Insert(const T& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		else
		{   
			PNode cur = _pRoot;
			PNode parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_data > data)
				{
					cur = cur->_left;
				}
				else if(cur->_data<data)
				{
					cur = cur->_right;
				}
				else return false;
			}
			cur = new Node(data);
			if (data < parent->_data)
				parent->_left = cur;
			else
				parent->_right = cur;
		}
		return true;
	}
	bool Erase(const T& data)
	{
		Node* parent = nullptr;
		Node* cur = _pRoot;
		//找到对应节点，保存父节点
		while (cur)
		{
			if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data>data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//准备删除
				if (cur->_left == nullptr)
				{
					if (cur == _pRoot)
					{
						_pRoot = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _pRoot)
					{
						_pRoot = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else //左右都不为空
				{
					//求右树的最小节点
					parent = cur;
					PNode subLeft = parent->_right;
					while (subLeft->_left)
					{
						parent = subLeft;
						subLeft = subLeft->_left;
					}
					swap(cur->_data, subLeft->_data);
					parent->_left = subLeft->_right;
					delete subLeft;
					
				}
				break;
			}
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}

	bool FindR(const T& data)
	{
		return _FindR(_pRoot, data);
	}
	bool InsertR(const T& data)
	{
		return _InsertR(_pRoot, data);
	}
	bool EraseR(const T& data)
	{
		return _EraseR(_pRoot, data);
	}
private:
	void _InOrder(PNode root)
	{
		if (root == nullptr) return;
		_InOrder(root->_left);		
		cout << root->_data << endl;
		_InOrder(root->_right);
	}
	bool _FindR(PNode root, const T& data)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_data < data)
		{
			return _FindR(root->_right, data);
		}
		else if (root->_data > data)
		{
			return _FindR(root->_left, data);
		}
		else return true;
	}
	bool _InsertR(PNode& root, const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			return true;
		}
		if (root->_data < data)
		{
			return _InsertR(root->_right, data);
		}
		else if (root->_data > data)
		{
			return _InsertR(root->_left, data);
		}
		else return true;
	}
	bool _EraseR(PNode& root, const T& data)
	{
		if (root == nullptr) return false;
		if (root->_data < data)
		{
			return _EraseR(root->_right, data);
		}
		else if (root->_data > data)
		{
			return _EraseR(root->_left, data);
		}
		else
		{
			if (root->_left == nullptr) root = root->_right;
			else if (root->_right == nullptr) root = root->_left;
			else
			{
				PNode subLeft = root->_right;
				while (subLeft->_left) subLeft = subLeft->_left;
				swap(root->_data, subLeft->_data);

				_EraseR(root->_right, data);
			}
		}
	}

	PNode _pRoot;
};
