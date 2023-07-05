#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int* cur = nums;
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            *cur = nums[i];
            cur++;
            j++;
        }
    }
    return j;
}

int main()
{
    int nums[8] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int j=removeElement(nums, 8, 2);

    return 0;
}