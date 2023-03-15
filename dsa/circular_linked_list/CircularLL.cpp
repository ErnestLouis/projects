#include "CircularLL.h"


CircularLL::CircularLL(int A[], int num_of_elements)
{
	Node* new_node, *tail;
	head = new Node;
	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < num_of_elements; i++)
	{
		new_node = new Node;
		new_node->data = A[i];
		new_node->next = tail->next;
		tail->next = new_node;
		tail = new_node;
	}

}

void CircularLL::display()
{
	Node* p = head;
	do 
	{
		std::cout << p->data << " ";
		p = p->next;
	} while (p != head);
}

CircularLL::~CircularLL()
{
	Node* p = head;
	while (p->next != head)
	{
		p = p->next;
	}

	while (p != head)
	{
		p->next = head->next;
		delete head;
		head = p-> next;
	}

	if (p == head)
	{
		delete head;
		head == nullptr;
	}

}