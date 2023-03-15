#pragma once
#include <iostream>


class Node
{
	public:
		int data;
		Node* next;
};


class CircularLL
{
	private:
		
		Node* head;

	public:

		CircularLL() {};
		CircularLL(int A[], int num_of_elements);
		~CircularLL();

		int get();
		int set(int index);
		void display();







};

