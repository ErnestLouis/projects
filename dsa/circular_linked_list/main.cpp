#include <iostream>
#include "CircularLL.h"


int main()
{
    int A[] = { 1,2,3,4,5 };

    CircularLL cirll(A, 5);

    cirll.display();
    std::cout << std::endl;
    std::cout << cirll.remove(0) << std::endl;;

    cirll.display();
}

