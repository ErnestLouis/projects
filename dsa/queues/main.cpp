#include <iostream>
#include "Arrqueue.h"
#include "Circ_arrqueue.h"
#include "Linkedqueue.h"

int main()
{
    Linkedqueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    q.display();

    q.dequeue();

    q.display();
}

