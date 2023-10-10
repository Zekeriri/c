#include <string>
#include <vector>
#include<iostream>
using namespace std;

string addStrings(string num1, string num2)
{
    string ret("");
    int result = 0;
    int carry = 0;
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    while (end1 >= 0 || end2 >= 0)
    {
        char x = end1 >= 0 ? num1[end1] : '0';
        char y = end2 >= 0 ? num2[end2] : '0';
        result = x + y - '0' * 2 + carry;
        carry = 0;
        if (result >= 10)
        {
            carry = 1;
            result = result % 10;
        }
        ret = (char)(result + '0') + ret;
        end1--;
        end2--;
    }
    if (carry == 1)
    {
        ret = '1' + ret;
    }
    return ret;
}
string multiply(string num1, string num2)
{
    string ret = "";
    int res = 0;
    int carry = 0;
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    if (end1 < end2)
    {
        swap(end1, end2);
        num1.swap(num2);
    }
    int n = end2;
    vector<string> result(end2 + 1, "");
    while (end2 >= 0)
    {
        int y = num2[end2] - '0';
        for (int i = end1; i >= 0; i--)
        {
            int x = num1[i] - '0';
            res = x * y + carry;
            carry = 0;
            if (res >= 10)
            {
                carry = res / 10;
                res = res % 10;
            }
            result[end2] = (char)(res + '0') + result[end2];
        }
        if (carry > 0)
        {
            result[end2] = (char)(carry + '0') + result[end2];
            carry = 0;
        }
        end2--;
    }
    for (int j = 0; j <= n; j++)
    {
        ret = ret + '0';
        ret = addStrings(ret, result[j]);
    }
    return ret;
}

int main()
{
    cout << multiply("999", "999");
    return 0;
}  