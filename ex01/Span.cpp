#include "./Span.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

Span::~Span() {}

Span::Span(const Span& other) {
	_v = other._v;
	_capacity = other._capacity;
}

Span::Span(unsigned int n) : _capacity(n) {
	_v.reserve(_capacity);
}

Span&	Span::operator=(const Span& other) {
	if (this != &other)
	{
		_v = other._v;
		_capacity = other._capacity;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (_v.size() >= _capacity)
		throw (ContainerFullException());
	_v.push_back(n);
} 

std::ostream& operator<<(std::ostream& ostr, const std::vector<int>& vector)
{
	std::vector<int>::const_iterator it = vector.begin();
    for ( ; it != vector.end(); ++it)
        ostr << ' ' << *it;
    return ostr;
}

unsigned int	Span::shortestSpan(void) const {
	if (_v.size() <= 1)
		throw (NoSpanException());
	std::vector<int>::const_iterator it = _v.begin();
	std::vector<int> vcpy;

	for(; it != _v.end(); ++it)
		vcpy.push_back(*it);

	std::sort(vcpy.begin(), vcpy.end());

	std::vector<int>::iterator it2 = vcpy.begin();
	int	tmp = *it2;
	int	tmp2;
	int	delta = (_v[0] > _v[1]) ? (_v[0] - _v[1]) : (_v[1] - _v[0]);
	int deltatmp;
	
	while (++it2 != vcpy.end())
	{
		tmp2 = *it2;
		if (tmp > tmp2)
			deltatmp = tmp - tmp2;
		else
			deltatmp = tmp2 - tmp;
		if (delta > deltatmp)
			delta = deltatmp;
		tmp = tmp2;
	}
	return (delta);
}

unsigned int	Span::longestSpan(void) const {
	if (_v.size() <= 1)
		throw (NoSpanException());
	std::vector<int>::const_iterator it = _v.begin();
	int shortest = *it;
	int longest = shortest;

	for(; it != _v.end(); ++it)
	{
		if (shortest > *it) shortest = *it;
		if (longest < *it) longest = *it;
	}
	return (longest - shortest);
}
