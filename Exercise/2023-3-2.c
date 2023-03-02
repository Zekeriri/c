//消失的数字
//1. 异或
int missingNumber(int* nums, int numsSize){
    int val=0;
    for (int i=0;i<numsSize;i++)
    {
        val^=nums[i];
    }
    for (int i=0;i<numsSize;i++)
    {
        val^=i;
    }
    return val;
}

//2. 求和
int missingNumber(int* nums, int numsSize){
    int val=numsSize*(numsSize+1)/2;
    // for (int i=0;i<numsSize+1;i++)
    // {
    //     val+=i;
    // }
    for (int i=0;i<numsSize;i++)
    {
        val-=nums[i];
    }
    
    return val;
}
//轮转数组
void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize;
    printf("[");
    for (int i = 0; i < numsSize; i++)
    {
        if (numsSize - k + i == numsSize)
        {
            k += numsSize;
        }

        printf("%d", nums[numsSize - k + i]);
        if (i != numsSize - 1)
        {
            printf(",");
        }
    }
    printf("]");
}
