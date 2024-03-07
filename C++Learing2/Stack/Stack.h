#pragma once
#include<vector>
using namespace std;
namespace bit
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
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
