#include"Date.h"
#include <assert.h>

struct SeqList
{
public:
	void PushBack(int x) 
	{
		_a[_size++] = x;
	}

	size_t size() const
	{
		return _size;
	}

	const int& operator[](size_t i) const
	{
		assert(i < _size);
		return _a[i];
	}
	int& operator[](size_t i)
	{
		assert(i < _size);
		return _a[i];
	}
private:
	int* _a = (int*)malloc(sizeof(int)*10);
	int _size = 0;
	int _capacity = 0;
};
class Stack
{
public:
	// 成员函数
	Stack(size_t n = 4)
		:a((int*)malloc(sizeof(int)*n))
		,top(0)
		,capacity(n)
	{
			if (a == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}
			memset(a, 0, sizeof(int) * n);
	}

	Stack(Stack& s)
	{
		a = (int*)malloc(sizeof(int) * s.capacity);
		if (a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		memcpy(a, s.a, sizeof(int) * (s.top));
		top = s.top;
		capacity = s.capacity;
	}

	void Push(int x)
	{
		if (top == capacity)
		{
			size_t newcapacity = capacity == 0 ? 4 : capacity * 2;
			a = (int*)realloc(a, sizeof(int) * newcapacity);
			if (a == nullptr)
			{
				perror("realloc fail");
				exit(-1);
			}
			capacity = newcapacity;
		}

		a[top++] = x;
	}
	int Top()
	{
		return a[top - 1];
	}
	void Pop()
	{
		assert(top);
		--top;
	}
	bool Empty()
	{
		return top == 0;
	}
	~Stack()
	{
		free(a);
		a = nullptr;
		top = capacity = 0;
	}
private:
	// 成员变量
	int* a;
	int top;
	int capacity;
};
class MyQueue
{
public:
	MyQueue(int capacity = 10)
		:_pushst(capacity)
		,_popst(capacity)
	{
	}
private:
	Stack _pushst;
	Stack _popst;
};
class A
{ 
public:
	class B
	{
	private:
		int _b;
	};
private:
	int _a;
};
struct ListNode
{
	ListNode* _next;
	int _val;

	ListNode(int val = 0)
		:_val(val)
		, _next(nullptr)
	{}
};

void TestSL()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);

	for (size_t i = 0; i < s.size(); i++)
	{
		s[i]++;
	}
}
void TestDate()
{
	Date d1(2023, 9, 27);
	Date d2(d1);
	d1.Print();
	d2.Print();
	//Date d3(2023, 10, 3);
	//d1 = d3;
	//d1.Print();
	//d1++;
	//++d1;
	//d1.Print();
	//cout << d1 - d2 << endl;
	cin >> d1;
	cout << d1;
}
int main()
{
	//TestDate();
	//TestSL();
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	return 0;
}