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

size_t	Span::shortestSpan(void) const {
	if (_v.size() <= 1)
		throw (NoSpanException());
	std::vector<int>::const_iterator	it = _v.begin();
	std::vector<int>					vcpy;

	for(; it != _v.end(); ++it)
		vcpy.push_back(*it);
	std::sort(vcpy.begin(), vcpy.end());

	std::vector<int>::const_iterator	it2 = vcpy.begin();
	long long							prev = *it2;
	long long							curr;
	long long							delta = static_cast<long long>(vcpy[1]) - static_cast<long long>(vcpy[0]);
	long long							deltatmp;
	
	while (++it2 != vcpy.end())
	{
		if (delta == 0)
			break;
		curr = *it2;
		deltatmp = curr - prev;
		if (delta > deltatmp)
			delta = deltatmp;
		prev = curr;
	}
	return (static_cast<size_t>(delta));
}

size_t	Span::longestSpan(void) const {
	if (_v.size() <= 1)
		throw (NoSpanException());
	std::vector<int>::const_iterator	it = _v.begin();
	long long							shortest = *it;
	long long							longest = shortest;

	for(; it != _v.end(); ++it)
	{
		if (shortest > *it) shortest = *it;
		if (longest < *it) longest = *it;
	}
	return (static_cast<size_t>(longest - shortest));
}
