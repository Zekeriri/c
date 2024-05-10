#include<iostream>
using namespace std;
#include"priority_queue.h"

int main()
{
	vector<int> v= { 2,4,3,1,4,9,0,8,8,4 };
	bit::priority_queue<int> pq(v.begin(), v.end());
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}