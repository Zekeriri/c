#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() 
{
    //1.const����һ�㳣��������
    int const a = 100;
    const int a = 100;
    int const arr[3] = { 1,2,3 };
    const int arr[3] = { 1,2,3 };

    //2.const����ָ��
    char* p = "hello";     
    // ��constָ��,
    // ��const����

    const char* p = "hello";  
    // ��constָ��,
    // const����
    *p = "123";
    p = &a;
    char* const p = "hello";   
    // constָ��,
    // ��const����
    *p = "123";
    p = &a;
    const char* const p = "hello";  
    // constָ��,
    // const����

}