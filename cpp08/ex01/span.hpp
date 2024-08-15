# pragma once

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <climits>

class Span{
    private:
        unsigned int _n;
        std::vector<int> _vec;
    public:
        // Default methods
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &element);

        // Member functions
        void addNumber(int nbr);
        int shortestSpan() const;
        int longestSpan() const;
        template<typename Iter>
        void fillSpan(Iter first, Iter last) {
            if (std::distance(first, last) + _vec.size() > _n)
                throw SpanFull();
            _vec.insert(_vec.end(), first, last);
        }

        // Exceptions
        class SpanFull : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class SpanTooSmall : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};