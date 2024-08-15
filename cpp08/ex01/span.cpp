# include "span.hpp"

// Default method
Span::Span() : _n(0) {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::~Span() {
}

Span::Span(const Span &copy) : _n(copy._n), _vec(copy._vec) {
}

Span &Span::operator=(const Span &element) {
    if (this != &element) {
        _n = element._n;
        _vec = element._vec;
    }
    return *this;
}

// Member function
void Span::addNumber(int nbr) {
    if (_vec.size() >= _n)
        throw SpanFull();
    _vec.push_back(nbr);
}

int Span::shortestSpan() const {
    if (_vec.size() < 2)
        throw SpanTooSmall();
    
    std::vector<int> sorted_vector = _vec;
    std::sort(sorted_vector.begin(), sorted_vector.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted_vector.size(); i++)
        minSpan = std::min(minSpan, sorted_vector[i] - sorted_vector[i - 1]);
    return minSpan;
}

int Span::longestSpan() const {
    if (_vec.size() < 2)
        throw SpanTooSmall();
    
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max-min;
}

// Exception
const char* Span::SpanFull::what() const throw() {
    return "Maximum size already reached!";
}
const char* Span::SpanTooSmall::what() const throw() {
    return "Not enough numbers to compute span!";
}