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

		CircularLL() { head = NULL; };
		CircularLL(int A[], int num_of_elements);
		~CircularLL();

		int get();
		int set(int index);
		int length();

		void display();
		void insert(int index, int num);
		int remove(int index);







};

