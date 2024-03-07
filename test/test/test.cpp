#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void TestListIterator1()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    list<int> l(array, array + sizeof(array) / sizeof(array[0]));

    auto it = l.begin();
    while (it != l.end())
    {
        // erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
        l.erase(it++);
        
    }
}

int main()
{
    TestListIterator1();
	return 0;
}
