#pragma once
#include<assert.h>
#include<iostream>

namespace bit
{
    template<class Iterator, class Ref, class Ptr>
    struct Reverse_iterator;

    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;

        typedef bit::Reverse_iterator<iterator, T&, T*> reverse_iterator;
        typedef bit::Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;


        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        iterator begin()
        {
            return _start;
        }
        iterator end() 
        {
            return _finish;
        }
        const_iterator begin()const
        {
            return _start;
        }
        const_iterator end()const
        {
            return _finish;
        }
        const_iterator cbegin() const
        {
            return _start;
        }
        const_iterator cend() const
        {
            return _finish;
        }
        // construct and destroy
        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr)
        {}
        vector(int n, const T& value = T())
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr)
        {
            reserve(n);
            while (n--)
            {
                push_back(value);
            }
        }
       
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (last > first)
            {
                push_back(*first);
                ++first;
            }
        }
        vector(const vector<T>& v)
        {
            vector tmp(v._start, v._finish);
            swap(tmp);
        }
        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }
        //capacity
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endOfStorage - _start;
        }
        void reserve(size_t n)
        {
            size_t sz = size();
            if (n > capacity())
            {
                iterator tmp = new T[n];
                if (_start)
                {
                    for (size_t i = 0; i < sz; i++)
                    {
                        tmp[i] = _start[i];
                    }
                }
                delete[] _start;
                _start = tmp;
                _finish = _start + sz;
                _endOfStorage = _start + n;
            }
            
        }
        void resize(size_t n, const T& value = T())
        {
            size_t sz=size();
            if (n < sz)
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capacity())
                {
                    reserve(n);
                    while (_finish != _start + n)
                    {
                        *_finish = value;
                        ++_finish;
                    }
                }
            }
            _finish = _start + n;
        }
        ///////////////access///////////////////////////////
        T& operator[](size_t pos)
        {
            assert(pos<size());
            return _start[pos];
        }
        const T& operator[](size_t pos)const
        {
            assert(pos<size());
            return _start[pos];
        }
        ///////////////modify/////////////////////////////
        void push_back(const T& x)
        {
            insert(_finish, x);
        }
        void pop_back()
        {
            erase(_finish - 1);
        }
        void swap(vector<T>& v)
        {
            std::swap(_finish,v._finish);
            std::swap(_start,v._start);
            std::swap(_endOfStorage,v._endOfStorage);
        }
        iterator insert(iterator pos, const T& x)
        {
            assert(pos <= _finish);
            assert(pos >= _start);
            if (_finish == _endOfStorage)
            {
                size_t len = pos - _start;
                size_t n = capacity();
                reserve(n == 0 ? 4 : n * 2);
                pos = _start + len;
            }
            iterator end = _finish;
            while (end > pos)
            {
                *end = *(end - 1);
                end--;
            }
            *pos = x;
            ++_finish;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos < _finish);
            iterator end = pos;
            while (pos < _finish-1)
            {
                *pos = *(pos + 1);
                ++pos;
            }
            --_finish;
            return pos;
        }
    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
}

namespace bit
{
    // 适配器 -- 复用
    template<class Iterator, class Ref, class Ptr>
    struct Reverse_iterator
    {
        Iterator _it;
        typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
        Reverse_iterator(Iterator it)
            :_it(it)
        {}

        Ref operator*()
        {
            Iterator tmp = _it;
            return *(--tmp);
        }

        Ptr operator->()
        {
            return &(operator*());
        }
        Self& operator++()
        {
            --_it;
            return *this;
        }
        Self& operator--()
        {
            ++_it;
            return *this;
        }
        bool operator!=(const Self& s)
        {
            return _it != s._it;
        }
    };
}