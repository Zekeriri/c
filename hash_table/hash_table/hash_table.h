#pragma once
#include<vector>

namespace hl
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};
	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _s;
	};
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (auto e : key)
			{
				hash *= 31;
				hash += e;
			}
			return hash;
		}
	};
	struct HashFuncString
	{
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (auto e:key)
			{
				hash *= 31;
				hash += e;
			}
			return hash;
		}
	};
	template<class K,class V,class Hash=HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			// 负载因子0.7就扩容
			if (_n*10 /_tables.size()==7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V,Hash> newHT;
				newHT._tables.resize(newSize);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s==EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}
				_tables.swap(newHT._tables);
			}

			Hash hf;

			size_t hashi = hf(kv.first) % _tables.size();
			while (_tables[hashi]._s==EXIST)
			{
				hashi++;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._s = EXIST;
			++_n;

			return true;
		}
		HashData<K, V>* Find(const K& key)
		{
			Hash hf;

			size_t hashi = hf(key) % _tables.size();
			while (_tables[hashi]._s != EMPTY)
			{
				if (_tables[hashi]._s == EXIST && _tables[hashi]._kv.first==key)
				{
					return &_tables[hashi];
				}
				hashi++;
				hashi %= _tables.size();
			}
			return nullptr;
		}
		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._s == EXIST)
				{
					cout << "[" << i << "]->" << _tables[i]._kv.first << ":"<<_tables[i]._kv.second<<endl;
				}
				else if (_tables[i]._s == EMPTY)
				{
					cout << "[" << i << "]->" << endl;
				}
				else
				{
					cout << "[" << i << "]->D" << endl;
				}
			}

		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_s = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}
	
	private:
		vector<HashData<K,V>> _tables;
		size_t _n = 0;
	};
	void TestHT1()
	{
		int a[] = { 4,14,24,34,5,7,1 };
		HashTable<int, int> ht;
		for (auto e:a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Erase(3);
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}
	void TestHT2()
	{
		string arr[] = { "apple","apple","bird","cat","dog","apple"};
		HashTable<string, int> ht;
		for (auto& e:arr)
		{
			HashData<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}
		ht.Print();
	}
}

namespace hash_bucket
{
	template<class K,class V>
	struct HashNode
	{
		HashNode* _next;
		pair<K, V> _kv;

		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K,class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
		{
			_tables.resize(10);
		}
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}
		bool Insert(const pair<K, V>& kv)
		{
			// 负载因子最大到1
			if (_n==_tables.size())
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}
				_tables.swap(newHT._tables);
			}
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);
			//头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			return NULL;
		}
	private:
		vector<Node*> _tables;
		size_t _n;
	};

	void TestHT1()
	{
		int a[] = { 4,14,24,34,5,7,1 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
	}
}