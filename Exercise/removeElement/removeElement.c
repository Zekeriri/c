#include <string.h>

int removeElement(int* nums, int numsSize, int val) {
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            memmove(nums+i, nums +i+ 1, (numsSize - i - 1)*4);
            i--;
            numsSize--;
        }

    }
    return numsSize;
}
int main()
{
    int arr[] = { 2,1,13,3,2 };
    
    removeElement(arr, 4, 2);
    return 0;
}