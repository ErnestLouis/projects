// linked_list_dsa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
    public:
        int data;
        Node* next; //self-refrential sturcture
}*first =NULL;//global pointer

void create(int A[], int n)
{
    Node* t, * last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next=NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != 0)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
}

void rec_display(Node *p) {
    
    if (p != NULL)
    {
        std::cout << p->data << " ";
        rec_display(p->next);
    }


}

void rev_rec_display(Node* p) {

    if (p != NULL)
    {
        rev_rec_display(p->next);
        std::cout << p->data << " ";
    }


}


int count(Node* p)
{
    int num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    return num;
}
int rec_count(Node* p)
{
    if (p == 0)
        return 0;
    else
        return rec_count(p->next) + 1;
}

int sum(Node* p)
{
    int total = 0;
    while (p)
    {
        total = total + p->data;
        p = p->next;
    }
    return total;
}

int max(Node* p)
{
    int max_num{ INT_MIN };
    while (p) {
        if (p->data > max_num)
        {
            max_num = p->data;
        }
        p = p->next;
    }
    return max_num;
}

Node * search(Node* p, int key )
{
    while (p) 
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}



int main()
{
    int A[] = { 2,4,6,8,10 };

    create(A, 5);

    //rev_rec_display(first);

    //std::cout << "The total number of elements present is: " << rec_count(first);


    //std::cout << "The sum of of elements present is: " << sum(first);

    //std::cout << "The biggest number is: " << max(first);

    std::cout << "The key is found at address : " << search(first, 6) << std::endl;

    std::cout <<  &A[2];
}

/*
Node* p;

    p = new Node;

    p->data = 10;
    p->next = 0;

    //transversing
    while (p != 0)
    {
        std::cout << p->data;
        p = p->next;
    }






*/