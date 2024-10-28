#include <MutantStack.tpp>
#include <list>
#include <cassert>

void testMutantStack( void ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	assert(mstack.top() == 17);

	mstack.pop();
	assert(mstack.size() == 1);
	assert(mstack.top() == 5);

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	assert(mstack.size() == 5);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int> expectedValues;
	expectedValues.push_back(5);
	expectedValues.push_back(3);
	expectedValues.push_back(5);
	expectedValues.push_back(737);
	expectedValues.push_back(0);

	std::list<int>::iterator expectedIt = expectedValues.begin();

	while (it != ite) {
		assert(*it == *expectedIt);
		++it;
		++expectedIt;
	}

	std::stack<int> s(mstack);
	assert(s.size() == mstack.size());
	assert(s.top() == mstack.top());
}

void testList( void ) {
	std::list<int> mList;

	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	mList.push_back(0);
	assert(mList.size() == 4);

	std::list<int>::iterator listCurrentIterator = mList.begin();
	std::list<int>::iterator listEndIterator = mList.end();

	std::list<int> expectedValues;

	expectedValues.push_back(3);
	expectedValues.push_back(5);
	expectedValues.push_back(737);
	expectedValues.push_back(0);
	std::list<int>::iterator expectedIt = expectedValues.begin();

	while (listCurrentIterator != listEndIterator) {
		assert(*listCurrentIterator == *expectedIt);
		++listCurrentIterator;
		++expectedIt;
	}
}

void	test42( void ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

int main( void ) {
	testMutantStack();
	testList();
	test42();
	std::cout << "All tests passed!" << std::endl;
	return 0;
}
