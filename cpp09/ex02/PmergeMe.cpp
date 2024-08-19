# include "PmergeMe.hpp"

template <typename Container>
void print_container(Container &container, std::string cont_type) {
	typename Container::iterator curr = container.begin();
	typename Container::iterator last = container.end();
	
	std::cout << cont_type << " values: ";
	while (curr != last) {
		std::cout << *curr << " ";
		curr++;
	}
	std::cout << std::endl;
}

bool isPositiveInteger(const std::string &arg) {
	if (arg.empty())
		return false;
	
	for (std::string::const_iterator it = arg.begin(); it != arg.end(); it++) {
		if (!std::isdigit(*it))
			return false;
	}

	int nbr = std::atoi(arg.c_str());
	return nbr > 0;
}

int binarySearchInsertPosition(const std::list<int>& sortedSeq, int value, int end) {
	int low = 0, high = end - 1;
	std::list<int>::const_iterator it;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		it = sortedSeq.begin();
		std::advance(it, mid);
   	if (*it < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

int binarySearchInsertPosition(const std::vector<int>& sortedSeq, int value, int end) {
	int low = 0, high = end - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (sortedSeq[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

template <typename Container>
void mergeInsertionSort(Container &container) {
	int n = container.size();
	// Base case: if container is of size 1 or empty, it is already sorted
	if (n <= 1) return;

	// Step 1: Group the elements into pairs
	Container largerElements, smallerElements;

	typename Container::iterator it = container.begin();
	for (int i = 0; i < n / 2; ++i) {
   	typename Container::iterator first = it++;
   	typename Container::iterator second = it++;
   	// Step 2: Compare pairs and separate into larger and smaller
   	if (*first > *second) {
      	largerElements.push_back(*first);
      	smallerElements.push_back(*second);
   	} else {
      	largerElements.push_back(*second);
      	smallerElements.push_back(*first);
   	}
	}

	// If odd, the last element remains unpaired
	if (n % 2 != 0) {
   	smallerElements.push_back(*it);
	}

	// Step 3: Recursively sort the larger elements
	mergeInsertionSort(largerElements);
	mergeInsertionSort(smallerElements);

	// Step 4: Insert the first element paired with the smallest of the largerElements
	Container sortedSeq;
	sortedSeq.push_back(smallerElements.front());
	sortedSeq.push_back(largerElements.front());

	// Step 5: Handle the remaining elements with special insertion order
	typename Container::iterator largerIt = ++largerElements.begin();
	typename Container::iterator smallerIt = ++smallerElements.begin();

	while (largerIt != largerElements.end()) {
		// Use binary search to insert the remaining elements based on the specially chosen ordering
   	int pos = binarySearchInsertPosition(sortedSeq, *smallerIt, sortedSeq.size());
   	typename Container::iterator insertPos = sortedSeq.begin();
   	std::advance(insertPos, pos);
		if (insertPos == sortedSeq.end())
			sortedSeq.push_back(*smallerIt);
		else
   		sortedSeq.insert(insertPos, *smallerIt);
   	sortedSeq.push_back(*largerIt);
   	++largerIt;
   	++smallerIt;
	}

	// If there is any remaining unpaired element, insert it at the right position
	while (smallerIt != smallerElements.end()) {
		int pos = binarySearchInsertPosition(sortedSeq, *smallerIt, sortedSeq.size());
		typename Container::iterator insertPos = sortedSeq.begin();
		std::advance(insertPos, pos);
		if (insertPos == sortedSeq.end())
			sortedSeq.push_back(*smallerIt);
		else
			sortedSeq.insert(insertPos, *smallerIt);
		++smallerIt;
	}
	
	// Step 6: Copy sorted sequence back to the original container
	container.swap(sortedSeq);
}

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int argc, char **argv) {
	(void)argc;
	(void)argv;

	for (int i = 1; i < argc; i++) {
		std::string arg(argv[i]);

		if (!isPositiveInteger(arg))
			throw NegativeNumber();
		
		int nbr = std::atoi(arg.c_str());
		_vec.push_back(nbr);
		_list.push_back(nbr);
	}

	sort_vec();
	sort_list();

	std::cout << "Vector: " << std::boolalpha << std::is_sorted(_vec.begin(), _vec.end()) << std::endl;
	std::cout << "List: " << std::boolalpha << std::is_sorted(_list.begin(), _list.end()) << std::endl;
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vec(copy._vec), _list(copy._list) {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &element) {
	if (this != &element) {
		_vec = element._vec;
		_list = element._list;
	}
	return *this;
}

void PmergeMe::sort_vec() {
	std::clock_t start = std::clock();

	mergeInsertionSort(_vec);
	std::clock_t end = std::clock();
	
	print_container(_vec, "Vector");
	std::cout << std::endl;
	double time = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Vector Time: " << time << std::endl;
	std::cout << std::endl;
}

void PmergeMe::sort_list() {
	std::clock_t start = std::clock();
	
	mergeInsertionSort(_list);
	std::clock_t end = std::clock();

	print_container(_list, "List");
	std::cout << std::endl;
	double time = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "List Time: " << time << std::endl;
	std::cout << std::endl;
}

const char* PmergeMe::NegativeNumber::what() const throw() {
	return "Negative Number In Input";
}
