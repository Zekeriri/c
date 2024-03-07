#pragma once
#include<vector>

namespace dl 
{
	template<class T,class Container =vector<T>,class Compare=Less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			//½¨¶Ñ
			for (int i = (_con.size()-2)/2; i >=0; i--)
			{
				adjust_down(i);
			}
		}
		void adjust_up(int child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]); 
					child = parent;
					parent = (parent - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		
		void adjust_down(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size()
					&& com(_con[child] ,_con[child + 1]) )
				{
					child++;
				}
				if (com(_con[parent] ,_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size()-1);
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size() 
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}