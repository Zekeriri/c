#include<iostream>
using namespace std;
typedef int DataType;
template<class T>
class Stack
{
public:
	Stack(size_t capacity=4)
	{
		_array = new T[capacity];
		_capacity = capacity;
		_size = 0;
	}
	void Push(T data)
	{
		_array[_size] = data;
		_size++;
	}
	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
private:
	T* _array;
	int _capacity;
	int _size;
};
class A
{
public:
	A(int x=4, int y=5, int z=6)
		:_x(x)
	{
		/*this->x = x;
		this->y = y;
		this->z = z;*/
		_z = z;
	}
	void Print()
	{
		cout << _x << " " << _y << " " << _z << " ";
	}
private:
	int _x=1;
	int _y=2;
	int _z=3;
};
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
int main()
{
	string s1("12222");
	string::const_iterator it = s1.begin();
	while (it!=s1.end())
	{
		cout << *it << " ";
		++it;
	}
	for (auto ch : s1)
	{
		cout << ch << " ";
	}

	return 0;
} 
