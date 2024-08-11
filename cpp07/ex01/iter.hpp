# pragma once
# include <cstdlib>

template <typename T, typename Func>
void	iter(T *arr, size_t size, Func f) {
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void	print(const T &tmp) {
	std::cout << "Random printing function called on this element: " << tmp << std::endl;
}
