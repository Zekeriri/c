#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0;
    int j = 0;
    while (i<j+m&&j<n)
    {
        if (nums1[i] > nums2[j])
        {
            for (int k =m+n-2; k >=i; k--)
            {
                nums1[k + 1] = nums1[k];
            }
            nums1[i] = nums2[j];
            j++;
        }
        i++;
    }
    for (; i < m + n&&j<n; i++,j++)
    {
        nums1[i] = nums2[j];
    }
}

int main()
{
    int nums1[6] = {4,5,6,0,0,0};
    int m = 3; 
    int nums2[3] = {1,2,3};
    int n = 3;
    merge(nums1,6,m,nums2,3,n);

    return 0;
}