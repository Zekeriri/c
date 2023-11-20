#pragma once
#include<assert.h>
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	int _bf; //balance factor

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first<kv.first)
			{
				parent = cur;
				cur = cur->_right;
			} 
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}

			cur = new Node(kv);
			if (parent->_kv.first<kv.first)
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}

			while (parent)
			{
				if (cur==parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				
				if (parent->_bf==0)
				{
					break;
				}
				else if(parent->_bf==1||parent->_bf==-1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf==2 ||cur->_bf==1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 || cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf==2&&cur->_bf==-1)
					{
						RotareRL(parent);
					}
				}
				else
				{
					assert(false);
				}
			}

			return true;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			subR->_left = parent;

			Node* parentParent = parent->_parent;

			parent->_parent = subR;
			if (subRL)
			{
				subRL->_parent = parent;
			}

			if (_root==parent)
			{
				_root = subR;
				subR->parent = nullptr;
			}
			else
			{
				if (parentParent->_left==parent)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR; 
				}

				subR->_parent = parentParent;
			}
			parent->_bf = subR->_bf = 0;
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->left = subLR;
			subL->_right = parent;

			Node* parentParent = parent->_parent;

			parent->_parent = subL;
			if (subLR)
			{
				subLR->_parent = parent;
			}

			if (_root == parent)
			{
				_root = subL;
				subL->paretn = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}
				subL->_parent = parentParent;
			}
			parent->_bf = subL->_bf = 0;
		}
	}

	void RotareRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			//subRL自己就是新增
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			//subRL的左子树新增
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			//subRL的右子树新增
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}

		void RotateLR(Node * parent)
		{
			//...
			RotateL(parent->_left);
			RotateR(parent);
		}
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	int _Height(Node* root)
	{
		if (root==nullptr)
		{
			return 0;
		}

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
private:
	Node* _root=nullptr;
	bool _IsBalance(Node* root)
	{
		if (root==nullptr)
		{
			return true;
		}

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		if (rightHeight-leftHeight!=root->_bf)
		{
			cout << root->_kv.first << "平衡因子异常"<<endl;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left);
			&& _IsBalance(root->_right);
	}
};