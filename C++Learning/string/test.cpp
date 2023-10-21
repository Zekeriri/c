#include "string.h"

void test_string1()
{
	dl::string s1 = "11";
	s1 = "2222";
}

void test_string2()
{
	dl::string s1 = "123456789";
	dl::string::iterator it = s1.begin();
	while (it!=s1.end())
	{
		cout << *it;
		it++;
	}
	for (auto ch : s1)
	{
		cout << ch;
	}
}

int main()
{
	//test_string1();
	test_string2();
}