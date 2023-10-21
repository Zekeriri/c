#pragma once
namespace dl
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& x=T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> self;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		Iterator _it;
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		Reverse_iterator(Iterator it)
			:_it(it)
		{}
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
	};


	//template<class T>
	//struct __list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef __list_const_iterator self;
	//	Node* _node;
	//	__list_const_iterator(Node* node)
	//		:_node(node)
	//	{}
	//	self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	self operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	self operator--(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}
	//	bool operator!=(const self& s)
	//	{
	//		return _node != s._node;
	//	}
	//	bool operator==(const self& s)
	//	{
	//		return _node == s._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin()
		{
			//return iterator(_head->next);
			return _head->_next;
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		iterator end()
		{
			return _head;
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		const_reverse_iterator rbegin() const
		{
			// list_node<int>*
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list()
		{
			empty_init();
		}
		list(const list<T>&lt)
		{
			empty_init();
			for (auto e:lt)
			{
				push_back(e);
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		list<int>& operator=(const list<int>& lt)
		{
			swap(lt);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(iterator pos,const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);

			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;
			prev->_next = next;
			next->_prev = prev;
			_size--;

			return iterator(next);
		}
		size_t size()
		{
			return _size;
		}
	private:
		Node* _head;
		size_t _size;
	};
}