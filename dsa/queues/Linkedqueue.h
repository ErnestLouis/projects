#pragma once
#include <iostream>
class Node
{
	public:
		int data;
		Node* next;
};


class Linkedqueue
{
	private:
		Node* front;
		Node* rear;

	public:
		Linkedqueue();
		~Linkedqueue();


		void enqueue(int num);
		int dequeue();
		void display();
		bool is_empty();
};

