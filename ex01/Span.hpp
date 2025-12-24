#ifndef SPAN_HPP
# define SPAN_HPP

#include<vector>
#include <cstddef>
#include <exception>

class	Span {
	public:
		~Span(void);
		Span(const Span&);
		Span&	operator=(const Span&);

		Span(unsigned int n);
		void	addNumber(int n);
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
