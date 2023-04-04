#include "Priority_queue.h"
#include <cctype>


Priority_queue::Priority_queue()
{
	front = rear = -1;
	front1 = rear1 = -1;
	front2 = rear2 = -1;
	size = 10;
	Q1 = new Element[size];
	Q2 = new Element[size];
	Q3 = new Element[size];
	
}

Priority_queue::Priority_queue(int size)
{
	front = rear = -1;
	front1 = rear1 = -1;
	front2 = rear2 = -1;
	this->size = size;
	Q1 = new Element[size];
	Q2 = new Element[size];
	Q3 = new Element[size];
}

Element get_element()
{
	char ele;
	std::cin >> ele;

	switch (std::toupper(ele))
	{
		case 'A':
			return Element::A;
			break;
		case 'B':
			return Element::B;
			break;
		case 'C':
			return Element::C;
			break;
		case 'D':
			return Element::D;
			break;
		case 'E':
			return Element::E;
			break;
		case 'F':
			return Element::F;
			break;
	}
}

void Priority_queue::enqueue(Element ele, Priority level)
{
	switch (level)
	{
	case Priority::HIGH:
		if (rear == size - 1)
		{
			std::cout << "queue 1 is full\n";
		}
		else
		{
			rear++;
			Q1[rear] = ele;
		}

		break;

	case Priority::MEDIUM:
		if (rear1 == size - 1)
		{
			std::cout << "queue 2 is full\n";
		}
		else
		{
			rear1++;
			Q2[rear1] = ele;
		}

		break;

	case Priority::LOW:
		if (rear2 == size - 1)
		{
			std::cout << "queue 3 is full\n";
		}
		else
		{
			rear2++;
			Q3[rear2] = ele;
		}

		break;

	}
}

void Priority_queue::display()
{
	for (int i = front + 1; i <= rear; i++)
	{
		std::cout << as_char(Q1[i]) << " ";
	}
	std::cout << std::endl;

	for (int i = front1 + 1; i <= rear1; i++)
	{
		std::cout << as_char(Q2[i]) << " ";
	}
	std::cout << std::endl;

	for (int i = front2 + 1; i <= rear2; i++)
	{
		std::cout << as_char(Q3[i]) << " ";
	}
	std::cout << std::endl;
}

char Priority_queue::dequeue()
{
	char x = -1;
	if (!(front == rear))
	{
		front++;
		x = as_char(Q1[front]);
	}
	else if(!(front1 == rear1))
	{
		front1++;
		x = as_char(Q1[front1]);
	}
	else if (!(front2 == rear2))
	{
		front1++;
		x = as_char(Q1[front2]);
	}
	else
	{
		std::cout << "all queues are empty\n";
	}
	return x;
}





/*
Priority get_num(Priority num)
{
	switch (num)
	{
	case Priority::HIGH:


		break;

	case Priority::MEDIUM:


		break;

	case Priority::LOW:


		break;

	}

}

*/