#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack( void ) : std::stack<T>() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {
			if (this != &other)
				std::stack<T>::operator=(other);
		}
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { 
			return std::stack<T>::c.begin();
		}

		iterator end() {
			return std::stack<T>::c.end();
		}

};

#endif