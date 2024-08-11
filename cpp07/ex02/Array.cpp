# include "Array.hpp"

template<typename T>
Array<T>::Array() : _tab(nullptr), _n(0) {
	std::cout << "Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::~Array() {
	std::cout << "Deconstructor called" << std::endl;
	delete [] this->_tab;
}

template<typename T>
Array<T>::Array(unsigned int n) : _n(n) {
	std::cout << "Constructor called" << std::endl;
	this->_tab = new T[this->_n]();
}

template<typename T>
Array<T>::Array(const Array<T> &copy) : _n(copy.getN()) {
	std::cout << "Array copy constructor called" << std::endl;
	this->_tab = new T[_n];
	for (unsigned int i = 0; i < this->_n; i++)
		this->_tab[i] = copy._tab[i];
}

// OVERLOADED METHODS
template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &element) {
	if (this != &element)
	{
		delete [] this->_tab;
		this->_n = element._n;
		this->_tab = new T[this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
			this->_tab[i] = element._tab[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
	if (this->_n <= i)
		throw BadIndex();
	else
		return this->_tab[i];
}

// ACCESSOR METHODS
template<typename T>
unsigned int Array<T>::getN() const {
	return this->_n;
}

template<typename T>
T *Array<T>::getTab() const {
	return this->_tab;
}

// EXCEPTIONS
template<typename T>
const char* Array<T>::BadIndex::what() const throw() {
	return "Index out of bounds";
}