#pragma once
template<class Iterator>
class ReverseIterator
{
public:
	typedef ReverseIterator<Iterator> Self;

	ReverseIterator(Iterator it)
		:_it(it)
	{}

	Self& operator++()
	{
		--_it;
		return *this;
	}
	bool operator!=(const Self& s)
	{
		return _it != s._it;
	}
private:
	Iterator _it;
};