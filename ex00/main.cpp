#include <easyfind.hpp>
#include <cassert>

void test_vector( void ) {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}

	try {
		assert(*(easyfind(vec, 3)) == 3);
		std::cout << "Test Vector: Found 3" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Test Vector: Error: " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 6);
		std::cerr << "Test Vector: Error: 6 should not be found" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Test Vector: Correctly caught exception for 6" << std::endl;
	}
}

void test_list( void ) {
	std::list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i * 10);
	}

	try {
		assert(*(easyfind(lst, 30)) == 30);
		std::cout << "Test List: Found 30" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Test List: Error: " << e.what() << std::endl;
	}

	try {
		easyfind(lst, 60);
		std::cerr << "Test List: Error: 60 should not be found" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Test List: Correctly caught exception for 60" << std::endl;
	}
}

int	main( void ) {
	test_vector();
	test_list();
	return (0);
}