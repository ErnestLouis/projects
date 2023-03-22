#include "Stack.h"
#include <iostream>

Stack::Stack(int size)
{
	this->size = size;
	S = new int[size];
	this->top = -1;
}

Stack::~Stack()
{
	delete[] S;
	nullptr;
}



void Stack::push(int num)
{
	if (top == size - 1) 
	{
		std::cout << "Stack overflow\n";
	}
	else
	{
		top++;
		S[top] = num;
	}
}

int Stack::pop()
{
	int x = -1;
	if (top == - 1)
	{
		std::cout << "Stack underflow\n";
	}
	else
	{
		x = S[top];
		S[top] = NULL;
		top--;

		//x = S[top--];
	}
	return x;
}

void Stack::display()
{
	for (int i = top; i >= 0; i--)
	{
		std::cout << S[i] << std::endl;
	}
}

int Stack::peek(int index)
{
	int x = -1;
	if (top - index + 1 < 0)
	{
		std::cout << "Invalid Index \n";
	}
	x = S[top - index + 1];

	return x;
}

bool Stack::isEmpty()
{
	int x = -1;
	if (top == -1)
	{
		return true;
	}

	return false;
}

bool Stack::isFull()
{
	int x = -1;
	if (top == size -1)
	{
		return true;
	}

	return false;
}

int Stack::stackTop()
{
	if (!isEmpty())
	{
		return S[top];
	}
	return -1;
}