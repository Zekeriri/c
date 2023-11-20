#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
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