#pragma once
#include<vector>
#include<functional>
using namespace std;
namespace bit
{
	template<class T>
	class Less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x >y;
		}
	};

	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue()
		{};

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:c(first,last)
		{
			for (int i = (c.size()-2)/2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		bool empty() const
		{
			return c.empty();
		}

		size_t size() const
		{
			return c.size();
		}

		const T& top() const
		{
			return c.front();
		}

		void push(const T& x)
		{
			c.push_back(x);
			adjust_up(c.size()-1);
		}

		void pop()
		{
			swap(c.front(), c.back());
			c.pop_back();
			adjust_down(0);
		}

	private:

		Container c;
		Compare comp;
		void adjust_up(size_t child)
		{
			size_t parent;
			while (child>0)
			{
				parent = (child - 1) / 2;
				if (comp(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
				}
				else
				{
					break;
				}
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void adjust_down(size_t parent)
		{
			size_t child= parent * 2 + 1;
			while (child < c.size())
			{
				if (child+1<c.size()&&comp(c[child],c[child+1]))
				{
					++child;
				}
				if (comp(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
				}
				else
				{
					break;
				}
 				parent = child;
				child = parent * 2 + 1;;
			}

		}
	};
};