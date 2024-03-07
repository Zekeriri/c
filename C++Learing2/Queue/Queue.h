#pragma once
#include <list>
namespace bit
{
	template<class T, class Container = std::list<T>>
	class queue
	{
		void push()
		{
			_con.push_back();
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			_con.front();
		}

		const T& back()
		{
			_con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
