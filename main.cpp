#include <iostream>
#include "Stacks.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    VectorStack<int> test;
    cout << "ISEMPTY:" << test.isEmpty() << endl;
    test.push(5);
    test.push(8);
    test.push(3);
    test.push(11);
    test.push(12);
    test.pop();
    cout << "TOP:" << test.top() << endl;
    test.pop();
    cout << "ISEMPTY:" << test.isEmpty() << endl;
    test.pop();
    test.pop();
    test.pop();
    cout << "ISEMPTY:" << test.isEmpty() << endl;
    test.pop();


    return 0;
}
