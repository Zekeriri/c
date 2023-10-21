#include<iostream>
#include<vector>
using namespace std;
void singleNumber(vector<int> nums) {
    int bitmark = 1;
    int group1 = 0;
    int group2 = 0;
    int xor_result = 0;
    for (auto e : nums)
    {
        xor_result ^= e;
    }
    while ((xor_result & bitmark) == 0)
    {
        bitmark <<= 1;
    }
    for (auto e : nums)
    {
        if ((bitmark & e) != 0)
        {
            group1 ^= e;
        }
        else
        {
            group2 ^= e;
        }
    }
    cout<<group1<<" "<<group2;
}

int main()
{
    singleNumber({ 1,2,1,3,2,5 });
    return 0;
}
