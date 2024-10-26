#include <Span.hpp>
#include <cassert>

void testAddNumber( void ) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(11);
		assert(false);
	} catch (std::exception &e) {
		assert(true);
	}
}

void testShortestSpan( void ) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	assert(sp.shortestSpan() == 2);
}

void testLongestSpan( void ) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	assert(sp.longestSpan() == 14);
}

void	testAddNumberRange( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	sp.addNumber(v.begin(), v.end());
	assert(sp.shortestSpan() == 2);
	assert(sp.longestSpan() == 14);
}

void	testAddNumberRangeOutOfBounds( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	v.push_back(5);
	try {
		sp.addNumber(v.begin(), v.end());
		assert(false);
	} catch (std::exception &e) {
		assert(true);
	}
}

void	testAddNumberRangeEmpty( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	try {
		sp.addNumber(v.begin(), v.end());
		assert(true);
	} catch (std::exception &e) {
		assert(false);
	}
}

void	testAddNumberRangeOneElement( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(6);
	sp.addNumber(v.begin(), v.end());
	try {
		sp.addNumber(v.begin(), v.end());
		assert(true);
	} catch (std::exception &e) {
		assert(false);
	}
}

void	testAddNumberRangeTwoElements( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	sp.addNumber(v.begin(), v.end());
	assert(sp.shortestSpan() == 3);
	assert(sp.longestSpan() == 3);
}

void	testAddNumberRangeIntBounds( void ) {
	Span sp = Span(5);
	std::vector<int> v;
	v.push_back(INT_MAX);
	v.push_back(INT_MIN);
	sp.addNumber(v.begin(), v.end());
	assert(sp.shortestSpan() == static_cast<unsigned int>(INT_MAX) - static_cast<unsigned int>(INT_MIN));
	assert(sp.longestSpan() == static_cast<unsigned int>(INT_MAX) - static_cast<unsigned int>(INT_MIN));
}

void	testHugeSpan( void ) {
	Span sp = Span(500000);
	std::vector<int> v;
	for (int i = 0; i < 500000; i++)
		v.push_back(i);
	sp.addNumber(v.begin(), v.end());
	assert(sp.shortestSpan() == 1);
	assert(sp.longestSpan() == 499999);
}

int main( void ) {
	testAddNumber();
	testShortestSpan();
	testLongestSpan();
	testAddNumberRange();
	testAddNumberRangeOutOfBounds();
	testAddNumberRangeEmpty();
	testAddNumberRangeOneElement();
	testAddNumberRangeTwoElements();
	testAddNumberRangeIntBounds();
	testHugeSpan();
	std::cout << "All tests passed!" << std::endl;
	return 0;
}