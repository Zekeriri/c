#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#include"HashTable.h"
void TestHT1()
{
    bit::HashTable<int, int> ht;
    int a[] = { 4,14,24,34,5,7,1 };
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }

    ht.Insert(make_pair(3, 3));
    ht.Insert(make_pair(3, 3));
    ht.Insert(make_pair(-3, -3));
    ht.Print();

    ht.Erase(3);
    ht.Print();

    if (ht.Find(3))
    {
        cout << "3����" << endl;
    }
    else
    {
        cout << "3������" << endl;
    }

    ht.Insert(make_pair(3, 3));
    ht.Insert(make_pair(23, 3));
    ht.Print();
}

void TestHT2()
{
    string arr[] = { "�㽶", "���","ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
    //HashTable<string, int, HashFuncString> ht;
    bit::HashTable<string, int> ht;
    for (auto& e : arr)
    {
        //auto ret = ht.Find(e);
        bit::HashData<string, int>* ret = ht.Find(e);
        if (ret)
        {
            ret->_kv.second++;
        }
        else
        {
            ht.Insert(make_pair(e, 1));
        }
    }

    ht.Print();

    ht.Insert(make_pair("apple", 1));
    ht.Insert(make_pair("sort", 1));

    ht.Insert(make_pair("abc", 1));
    ht.Insert(make_pair("acb", 1));
    ht.Insert(make_pair("aad", 1));

    ht.Print();
}

int main()
{
	TestHT2();
	return 0;
}