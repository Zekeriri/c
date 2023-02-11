#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() 
{
    //1.const修饰一般常量及数组
    int const a = 100;
    const int a = 100;
    int const arr[3] = { 1,2,3 };
    const int arr[3] = { 1,2,3 };

    //2.const修饰指针
    char* p = "hello";     
    // 非const指针,
    // 非const数据

    const char* p = "hello";  
    // 非const指针,
    // const数据
    *p = "123";
    p = &a;
    char* const p = "hello";   
    // const指针,
    // 非const数据
    *p = "123";
    p = &a;
    const char* const p = "hello";  
    // const指针,
    // const数据

}