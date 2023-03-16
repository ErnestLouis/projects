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
		head = nullptr;
	}

}

int CircularLL::length()
{
	Node* p = head;
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != head);

	return len;
}

void CircularLL::insert(int index, int num)
{
	Node* p = head, *new_node;

	if (index < 0 || index > length())
		return;

	if (index == 0)
	{

		new_node = new Node;
		new_node->data = num;
		if (head == NULL)
		{
			head = new_node;
			head->next = head;
		}
		else
		{

			while (p->next != head)
			{
				p = p->next;
			}
			//new_node->next = p->next;
			new_node->next = head;
			p->next = new_node;
			head = new_node;

		}

	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		new_node = new Node;
		new_node->data = num;
		new_node->next = p->next;
		p->next = new_node;
	}
}

int CircularLL::remove(int index)
{
	Node* p = head, * q;
	int x;

	if (index < 0 || index > length())
		return -1;
	else if (index == 0)
	{
		while (p->next != head)
		{
			p = p->next;
		} 
		x = head->data;
		if (head == p)
		{
			delete head;
			head = NULL;
		}
		else
		{
			p->next = head->next;
			delete head;
			head = p->next;
		}

	}
	else
	{
		for (int i = 0; i < index - 2; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		x = q->data;
		q->next = NULL;
		delete q;
	}
	return x;
}