using namespace std;
#include"List.h"
void print_list(const bit::list<int>& lt)
{
	auto it = lt.rbegin();
	while (it != lt.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test_list1()
{
	bit::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	bit::list<int> lt1(lt);

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	print_list(lt1);
}

int main()
{
	test_list1();

	return 0;
}