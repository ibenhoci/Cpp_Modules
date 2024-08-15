# include "MutantStack.hpp"
# include <iostream>
# include <list>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  // Should print 17
    mstack.pop();
    std::cout << mstack.size() << std::endl;  // Should print 1 (only 5 left)
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test iterators
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;  // Move iterator forward
    --it;  // Move iterator backward
    while (it != ite) {
        std::cout << *it << std::endl;  // Should print the elements from bottom to top
        ++it;
    }

    // Test copying the stack into a std::stack
    std::stack<int> s(mstack);

    std::cout << "------------LIST OUTPUT-------------" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;  // Should print 17
    lst.pop_back();
    std::cout << lst.size() << std::endl;  // Should print 1 (only 5 left)
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    // Test iterators
    std::list<int>::iterator itL = lst.begin();
    std::list<int>::iterator iteL = lst.end();
    ++itL;  // Move iterator forward
    --itL;  // Move iterator backward
    while (itL != iteL) {
        std::cout << *itL << std::endl;  // Should print the elements from bottom to top
        ++itL;
    }
    return 0;
}
