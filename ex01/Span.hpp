#ifndef SPAN_HPP
# define SPAN_HPP

#include<vector>
#include <cstddef>
#include <exception>

#include <iostream>

class	Span {
	public:
		~Span(void);
		Span(const Span&);
		Span&	operator=(const Span&);

		Span(unsigned int n);
		void	addNumber(int n);

		template<typename inputIt>
		void	fillSpan(inputIt first, inputIt last) {
			for (; first != last; first++)
			{
				if (_v.size() >= _capacity)
					throw (ContainerFullException());
				_v.push_back(*first);
			}
		}

		class	ContainerFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Exception: cannot add new number, container is full or too small.\n");
				}
		};
		class	NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Exception: no span can be found, container is empty or contains single number).\n");
				}
		};
		size_t				longestSpan(void) const;
		size_t				shortestSpan(void) const;
		// add an overload on operator []
	private:
		std::size_t			_capacity;
		std::vector<int>	_v;
};

#endif // !SPAN_HPP
