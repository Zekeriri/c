#include "string.h"
namespace dl
{
	string::string(const char* str)
		:_size(strlen(str))
		, _capacity(_size)
	{
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	string::string(const string& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		string tmp(s._str);
		swap(tmp);
	}
	string& string::operator=(const string& s)
	{
		string tmp(s);
		swap(tmp);
		return *this;
	}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	const string::const_iterator string::begin() const
	{
		return _str;
	}
	const string::const_iterator string::end() const
	{
		return _str + _size;
	}

	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
	void string::swap(string& s)
	{
		std::swap(_capacity, s._capacity);
		std::swap(_size, s._size);
		std::swap(_str, s._str);
	}
	const char* string::c_str()const
	{
		return _str;
	}

	char& string::operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}
	const char& string::operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	size_t string::size()const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	void string::resize(size_t n, char c)
	{
		if (n < _size)
		{
			_str[_size] = '\0';
		}
		else
		{
			reserve(n);
			while (_size < n)
			{
				_str[_size] = c;
				_size++;
			}
			_str[_size] = '\0';
		}
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	bool string::operator<(const string& s)
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)
	{
		return *this < s || *this == s;
	}
	bool string::operator>(const string& s)
	{
		return !(*this <= s);
	}
	bool string::operator>=(const string& s)
	{
		return !(*this < s);
	}
	bool string::operator==(const string& s)
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s)
	{
		return !(*this == s);
	}
	// 返回c在string中第一次出现的位置
	size_t string::find(char c, size_t pos) const
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}
		return npos;
	}
	// 返回子串s在string中第一次出现的位置
	size_t string::find(const char* s, size_t pos) const
	{
		const char* p = strstr(_str + pos, s);
		if (p)
		{
			return p - _str;
		}
		else
		{
			return npos;
		}
	}
	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_size++;

		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			end--;
		}
		strncpy(_str + pos, str, len);
		_size += len;
		return *this;
	}
	// 删除pos位置上的元素，并返回该元素的下一个位置
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < len);
		if (len == npos || pos + len > _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t begin = pos + len;
			while (begin < _size)
			{
				_str[begin - len] = _str[begin];
				++begin;
			}
			_size -= len;
		}
		return *this;
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buff[129];
		size_t i = 0;

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 129)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}
