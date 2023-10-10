#include"string.h"
const static size_t npos = 0;
void test_string1()
{
	dl::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.insert(5, '%');
	cout << s1<< endl;
	cin >> s1;
	cout << s1 << endl;
}
int main()
{
	test_string1();
}