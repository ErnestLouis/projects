#include <iostream>
#include "Arrqueue.h"
#include "Circ_arrqueue.h"
#include "Linkedqueue.h"
#include "Priority_queue.h"

int main()
{
    Priority_queue q(5);

    q.enqueue(Element::A, Priority::HIGH);
    q.enqueue(Element::B, Priority::MEDIUM);
    q.enqueue(Element::C, Priority::LOW);

    q.enqueue(get_element(), Priority::HIGH);

    q.display();

}
/*

    Linkedqueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    q.display();

    q.dequeue();

    q.display();


*/