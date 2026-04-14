#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> m;

    m.push(5);
    m.push(17);
    m.push(3);
    m.push(42);

    for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}