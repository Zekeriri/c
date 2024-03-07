#include<iostream>
#include <vector>
using namespace std;
bool areAllElenmtsEqual(vector<int>& numbers)
{
    for (int i=1; i<numbers.size(); i++) {
        if (numbers[i]!=numbers[i-1]) 
        {
            return false;
        }
    }
    return true;
}

int MoreThanHalfNum_Solution(vector<int>& numbers) 
{
    // write code here
    int i=0;
    while(1)
    {
        for (int i=0; i<numbers.size(); i+=2) 
        {
            if (numbers[i]!=numbers[i+1]) 
            {
                numbers.erase(numbers.begin()+i, numbers.begin()+i+2);
                i-=2;
            }
        }
        if (areAllElenmtsEqual(numbers))
        {
            int ret=numbers[0];
            return ret;
        }
    }
}

int main()
{
    vector<int> a = { 1,2,3,2,2,2,5,4,2 };
    cout << MoreThanHalfNum_Solution(a);
}