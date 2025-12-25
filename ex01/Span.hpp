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
			size_t	len = 0;
			inputIt fcpy = first;
			for (;fcpy != last; fcpy++)
				len++;
			for (size_t i = 0; first != last; first++, i++)
			{
				if (i >= _v.capacity())
					throw (ContainerFullException());
				_v.push_back(*first);
			}
		}

		class	ContainerFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Exception: cannot add new number, container is full.\n");
				}
		};
		class	NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Exception: no span can be found (no numbers or only one).\n");
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
