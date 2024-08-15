# pragma once 

# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        MutantStack &operator=(const MutantStack &element) {
            if (this != &element)
                std::stack<T>::operator=(element);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {
            return this->c.rbegin();
        }
        reverse_iterator rend() {
            return this->c.rend();
        }

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }

        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }
        const_reverse_iterator rend() const {
            return this->c.rend();
        }
};