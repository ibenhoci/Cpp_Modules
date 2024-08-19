# pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>
# include <cmath>
# include <iterator>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::list<int> _list;
		PmergeMe();
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &element);

		void sort_vec();
		void sort_list();

		class NegativeNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};