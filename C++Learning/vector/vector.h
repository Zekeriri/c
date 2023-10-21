#pragma once
#include<assert.h>
namespace dl
{
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

	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

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
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		vector()
		{}
		vector(size_t n,const T val=T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v) 
		{
			reserve(v.capacity());
			for (auto& e:v)
			{
				push_back(e);
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n ,const T& val =T())
		{
			if (n<=size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish<_start+n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		void push_back(const T& x)
		{
			//if (_finish == _endofstorage)
			//{
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);
			//}
			//*_finish = x;
			//++_finish;
			insert(end(), x);
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish ==_endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;

			return pos; 
		}


	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _endofstorage=nullptr;
	};
}
