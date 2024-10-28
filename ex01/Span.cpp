#include <Span.hpp>

Span::Span( void ): _N(0) {}

Span::Span( unsigned int N ): _N(N) {}

Span::Span( const Span &obj ) {
	if (this != &obj) {
		_N = obj._N;
		_span = obj._span;
	}
}

Span	&Span::operator=(const Span &obj) {
	if (this != &obj) {
		_N = obj._N;
		_span = obj._span;
	}
	return (*this);
}

Span::~Span( void ) {}

void	Span::addNumber( int n ) {
	if (_span.size() < _N) {
		_span.push_back(n);
		return ;
	}
	throw std::runtime_error("Error: <Out Of Bounds> Span is has no space left");
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
	if (_span.size() + std::distance(begin, end) <= _N) {
		_span.insert(_span.end(), begin, end);
		return ;
	}
	throw std::runtime_error("Error: <Out Of Bounds> Span is has no space left");
}

unsigned int	Span::longestSpan( void ) {
	if (_span.size() < 2)
		throw std::runtime_error("Error: Can't establish a span with less than two elements");
	std::vector<int>::iterator max = std::max_element(_span.begin(), _span.end());
	std::vector<int>::iterator min = std::min_element(_span.begin(), _span.end());
	return (*max - *min);
}

unsigned int	Span::shortestSpan( void ) {
	if (_span.size() < 2)
		throw std::runtime_error("Error: Can't establish a span with less than two elements");
	std::vector<int> sorted = _span;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = sorted.begin();
	unsigned int span = std::numeric_limits<unsigned int>::max();

	while (it != sorted.end() - 1) {
		if (span > static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it))
			span = static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it);
		it++;
	}
	return (span);
}