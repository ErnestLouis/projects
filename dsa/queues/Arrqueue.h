#pragma once
#include <iostream>

class Arrqueue
{
	private:
		int size;
		int front;
		int rear;
		int* Q; //for creating a n array size
	
	public:
		Arrqueue();
		Arrqueue(int size);
		
		void enqueue(int x);
		void display();
		int dequeue();
};

