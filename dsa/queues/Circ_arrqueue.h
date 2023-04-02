#pragma once
#include <iostream>


class Circ_arrqueue
{
private:
	int size;
	int front;
	int rear;
	int* Q; //for creating a n array size

public:
	Circ_arrqueue();
	Circ_arrqueue(int size);
	~Circ_arrqueue();
	void enqueue(int x);
	void display();
	int dequeue();
	bool is_full();
	bool is_empty();

};

