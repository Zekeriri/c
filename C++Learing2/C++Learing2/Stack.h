#pragma once
#include<iostream>

template<class T>
class Stack
{
public:
	void Push(const T& x);
	void Pop();
private:
	T* _a = nullptr;
	int _top = 0;
	int _capacity = 0;
};

template<class T>
void Stack<T>::Push(const T& x)
{
	cout << "void Stack<T>::Push(const T& x)" << endl;
}

template<class T>
void Stack<T>::Pop()
{
	cout << "Stack<T>::void Pop()" << endl;
}