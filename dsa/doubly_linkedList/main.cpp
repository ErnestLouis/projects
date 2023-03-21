#include <iostream>
#include "DoublyLL.h"

int main()
{
    int A[] = { 10,20,30,40,50,60,70,80,90,100};

    DoublyLL dub(A, arr_size(A));

    dub.display();

   // dub.insert(6, 777);

   // std::cout << "deleted: " << dub.remove(3) << std::endl;

    dub.reverse();

    dub.display();


}

