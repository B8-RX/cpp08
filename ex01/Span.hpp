#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
class	Span {
	public:
		Span(void);
		~Span(void);
		Span(const Span&);
		Span&	operator=(const Span&);

		Span(int n);
		void	addNumber(int n);
		class	FullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Exception: Set is full\n");
				}
		}
	private:
		// std::set || std::list || std::deque || std::vector
};

#endif // !SPAN_HPP
