#include <iostream>
#include "Arrqueue.h"

int main()
{
    Arrqueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
}

