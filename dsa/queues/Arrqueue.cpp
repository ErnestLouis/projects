#include "Arrqueue.h"

Arrqueue::Arrqueue()
{
	front = rear = -1;
	size = 10;
	Q = new int[size];
}


Arrqueue::Arrqueue(int size)
{
	front = rear = -1;
	this->size = size;
	Q = new int[this->size];
}

void Arrqueue::enqueue(int x)
{
	if (rear == size - 1)
	{
		std::cout << "queue is full\n";
	}
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int Arrqueue::dequeue()
{
	int x = -1;
	if (front == rear)
	{
		std::cout << "queue is empty\n";
	}
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

void Arrqueue::display()
{
	for (int i = front + 1; i <= rear; i++)
	{
		std::cout << Q[i] << " ";
	}
	std::cout << std::endl; 
}