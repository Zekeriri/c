#include<iostream>
using namespace std;
#include"SmartPtr.h"

void TestSmartPtr()
{
	SmartPtr<int> sp1(new int);
}

int main()
{
	TestSmartPtr();

	return 0;
}