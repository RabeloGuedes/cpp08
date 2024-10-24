#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int value) {
	typename T::iterator i = std::find(container.begin(), container.end(), value);
	if (i != container.end())
		return i;
	throw std::runtime_error("Value not found in container");
}

#endif