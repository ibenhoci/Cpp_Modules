# pragma once

# include <iostream>
# include <exception>

template<typename T>

class Array {
    private:
        T               *_tab;
        unsigned int    _n;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array<T> &copy);
        // OPERATOR OVERLOAD
        Array<T> &operator=(const Array<T> &element);
        T &operator[](unsigned int i);

        // ACCESSOR METHODS
        unsigned int getN() const;
        T *getTab() const;
        
        class BadIndex : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};