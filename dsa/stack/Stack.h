#pragma once
class Stack
{
	private:
		int size; 
		int top; //top pointer
		int* S;// pointer to array

	public:
		Stack() = default;
		Stack(int size);
		~Stack();

		void display();
		void push(int num);
		int pop();

		int peek(int index);
		
		bool isEmpty();
		bool isFull();

		int stackTop();

};

