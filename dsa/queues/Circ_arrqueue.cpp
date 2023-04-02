#include "Circ_arrqueue.h"


Circ_arrqueue::Circ_arrqueue()
{
	front = 0;
	rear = 0;
	size = 10;
	Q = new int[size];
}


Circ_arrqueue::Circ_arrqueue(int size)
{
	front = 0;
	rear = 0;
	this->size = size;
	Q = new int[size];
}

Circ_arrqueue::~Circ_arrqueue()
{
	delete[] Q;
}


bool Circ_arrqueue::is_full()
{
	if ((rear + 1) % size == front)
	{
		return true;
	}
	return false;
}

bool Circ_arrqueue::is_empty()
{
	if (front == rear)
	{
		return true;
	}
	return false;
}

void Circ_arrqueue::enqueue(int x)
{
	if (is_full())
	{
		std::cout << "queue overflow\n";
	}
	else
	{
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}

int Circ_arrqueue::dequeue()
{
	int x = -1;
	if (is_empty())
	{
		std::cout << "queue underflow\n";
	}
	else
	{
		front = (front + 1) % size;
		x = Q[front];
	}
	return x;
}

void Circ_arrqueue::display()
{

	int i = (front + 1) % size;
	while (i != (rear + 1) % size)
	{
		std::cout << Q[i] << std::flush;
		if (i < rear)
		{
			std::cout << " <- " << std::flush;
		}
		i = (i + 1) % size;
	} ;
	std::cout << std::endl;
}