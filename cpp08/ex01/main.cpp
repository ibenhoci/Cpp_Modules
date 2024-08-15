# include "span.hpp"
# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

int main() {
    // Test Case 1: Basic functionality
    try {
        std::cout << "Test Case 1: Basic Functionality\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test Case 2: Range-based addition
    try {
        std::cout << "\nTest Case 2: Range-based Addition\n";
        Span sp(10);
        std::vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        sp.fillSpan(numbers.begin(), numbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    } 
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test Case 3: Adding more numbers than capacity
    try {
        std::cout << "\nTest Case 3: Adding More Numbers than Capacity\n";
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);  // Should throw SpanFull exception

    }
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test Case 4: Not enough numbers to compute span
    try {
        std::cout << "\nTest Case 4: Not Enough Numbers to Compute Span\n";
        Span sp(2);
        sp.addNumber(5);
        int smallspan = sp.shortestSpan();
        int lspan = sp.longestSpan();
        std::cout << "Shortest Span: " << smallspan << std::endl;  // Should throw SpanTooSmall exception
        std::cout << "Longest Span: " << lspan << std::endl;

    }
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test Case 5: Performance Test with 10,000 numbers
    try {
        std::cout << "\nTest Case 5: Performance Test with 10,000 Numbers\n";
        Span sp(10000);
        std::vector<int> large_numbers;
        for (int i = 0; i < 10000; ++i) {
            large_numbers.push_back(rand() % 100000);  // Random numbers between 0 and 100,000
        }
        sp.fillSpan(large_numbers.begin(), large_numbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
