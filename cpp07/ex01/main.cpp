# include <iostream>
# include "iter.hpp"

int main(void) {
	int			arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char		c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	std::string mat[3] = {
		"First sentence",
		"Second sentence",
		"Third sentence",
	};

	iter(arr, 10, print<int>);
	std::cout << std::endl;

	iter(c, 10, print<char>);
	std::cout << std::endl;

	iter(mat, 3, print<std::string>);
	std::cout << std::endl;
}