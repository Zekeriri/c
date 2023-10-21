#pragma once
#include <deque>;
namespace dl
{
	template <class T,class Container=std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};


}
