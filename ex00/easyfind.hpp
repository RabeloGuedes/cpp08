#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    // try {
        typename T::const_iterator it = container.begin();
		for (; it != container.end(); ++it) {
			if (*it == value)
				return (it);
		}
        throw std::runtime_error("Value not found in container");
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return container.end();
    // }
}

template <typename T>
typename T::iterator	easyfind(T &container, int value) {
	// try {
		typename T::iterator it = container.begin();
		for (; it != container.end(); ++it) {
			if (*it == value)
				return (it);
		}
		throw std::runtime_error("Value not found in container");
	// } catch (const std::exception& e) {
	//     std::cerr << "Error: " << e.what() << std::endl;
	//     return container.end();
	// }
}

#endif