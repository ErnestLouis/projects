#include "Linkedqueue.h"

Linkedqueue::Linkedqueue()
{
	front = nullptr;
	rear = nullptr;
}

Linkedqueue::~Linkedqueue() 
{
	Node* p = front;
	while (front)
	{
		front = front->next;
		delete  p;
		p = front;
	}

}


void Linkedqueue::enqueue(int num)
{
	Node* new_node = new Node;
	if (new_node == NULL)
	{
		std::cout << "Queue overflow" << std::endl;
	}
	else
	{
		new_node->data = num;
		new_node->next = nullptr;
		if (front == NULL)
		{
			front = rear = new_node;
		}
		else
		{
			rear->next = new_node;
			rear = new_node;
		}
	}
}

bool Linkedqueue::is_empty()
{
	if (front == nullptr)
	{
		return true;
	}
	return false;
}

int Linkedqueue::dequeue()
{
	int x = -1;
	Node* p;
	if (is_empty())
	{
		std::cout << "Queue underflow" << std::endl;
	}
	else
	{
		p = front;
		front = front->next;
		x = p->data;
		delete p;
	}
	return x;
}


void Linkedqueue::display()
{
	Node* p = front;
	while (p)
	{
		std::cout << p->data << std::flush;
		p = p->next;
		if (p != nullptr)
		{
			std::cout << " <- " << std::flush;
		}
	}
	std::cout << std::endl;
}
