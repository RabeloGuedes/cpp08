#ifndef	SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <limits>

class Span {
	private:
		Span( void );
		unsigned int	_N;
		std::vector<int> _span;

	public:
		Span(unsigned int N);
		Span(const Span &obj);
		Span	&operator=(const Span &obj);
		~Span( void );
		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );
};

#endif