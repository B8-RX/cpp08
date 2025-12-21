#include "./Span.hpp"
#include <vector>
#include <iostream>

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
