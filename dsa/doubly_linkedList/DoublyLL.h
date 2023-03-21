#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Node
{
	public:
		Node* prev;
		int data;
		Node* next;
};

class DoublyLL
{
	private:
		Node* first;

	public:
		DoublyLL() { first = NULL; }
		DoublyLL(int A[], int n);

		void display();
		int length();
		void insert(int index, int value);
		int remove(int index);
		void reverse();
};

int arr_size(int A[]);