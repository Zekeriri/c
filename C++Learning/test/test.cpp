#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	map<string, int> countMap;

	//for (auto& str : arr)
	//{
	//	auto ret = countMap.find(str);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}
	for (auto& str : arr)
	{
		countMap[str]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}