#include "doublyLL.h"



DoublyLL::DoublyLL(int A[], int num_of_elements)
{
	Node *new_node, * last;

	first = new Node;
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (int i = 1; i < num_of_elements; i++)
	{
		new_node = new Node;
		new_node->data = A[i];
		new_node->next = last->next;
		new_node->prev = last;
		last->next = new_node;
		last = new_node;
	}

}

void DoublyLL::display()
{
	Node* p = first;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int DoublyLL::length()
{
	Node* p = first;
	int count = 0;

	while (p)
	{
		count++;
		p = p->next;
	}

	return count;
}

void DoublyLL::insert(int index, int value)
{
	Node* p = first, * last, *new_node;

	if (index < 0 || index > length())
		return;

	if (index == 0)
	{
		new_node = new Node;
		new_node->data = value;
		new_node->prev = NULL;
		new_node->next = first;
		first->prev = new_node;
		first = new_node;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		new_node = new Node;
		new_node->data = value;
		new_node->next = p->next;
		new_node->prev = p;
		if (p->next) {
			p->next->prev = new_node;
		}
		p->next = new_node;
	}
}

int arr_size(int A[])
{
	int j = 0;
	int* a = new int[25];

	for (int i = 0; i < 25; i++)
	{
		a[i] = NULL;
	}

	a[0] = A[0];

	while (A[j] > -25)
	{
		a[j] = A[j];
		j++;
	}
	delete[] a;


	return j;
}

int DoublyLL::remove(int index)
{
	Node* p = first;
	int x;

	if (index < 0 || index > length())
		return -1;

	if (index == 0)
	{
		first = first->next;
		x = p->data;
		delete p;
		if (first)
		{
			first->prev = NULL;
		}
	}
	else
	{

		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		x = p->data;
		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;
		//if you try to access nulls next or nulls prev that is an error
		delete p;
	}
	return x;
}

void DoublyLL::reverse()
{
	Node* p = first;
	Node* temp;
	while (p != nullptr)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;


		if (p->next == nullptr)
		{
			p->next = p->prev;
			p->prev = nullptr;
			first = p;
			break;
		}
	}

}