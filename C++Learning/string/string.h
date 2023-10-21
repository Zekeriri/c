#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
#include<string.h>
using namespace std;
namespace dl
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const dl::string& s);
        friend istream& operator>>(istream& _cin, dl::string& s);
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
    public:
        string(const char* str = "");
        string(const string& s);
        string& operator=(const string& s);
        ~string();
        // iterator
        iterator begin();
        iterator end();
        const const_iterator begin() const;
        const const_iterator end() const;
        // modify
        void push_back(char c);
        string& operator+=(char c);
        void append(const char* str);
        string& operator+=(const char* str);
        void clear();
        void swap(string& s);
        const char* c_str()const;
        // capacity
        size_t size()const;
        size_t capacity()const;
        void resize(size_t n, char c = '\0');
        void reserve(size_t n);
        // access
        char& operator[](size_t index);
        const char& operator[](size_t index)const;
        //relational operators
        bool operator<(const string& s);
        bool operator<=(const string& s);
        bool operator>(const string& s);
        bool operator>=(const string& s);
        bool operator==(const string& s);
        bool operator!=(const string& s);
        // ����c��string�е�һ�γ��ֵ�λ��
        size_t find(char c, size_t pos = 0) const;
        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��
        size_t find(const char* s, size_t pos = 0) const;
        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);
        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
        string& erase(size_t pos, size_t len=npos);
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    public:
        const static size_t npos;
    };
    const size_t string::npos = -1;
}