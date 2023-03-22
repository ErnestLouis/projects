

#include <iostream>
#include <string>
#include "Stack.h"

//void print(std::string str1);

int main()
{

	Stack st1(5);

	//print("Enter size of stack: ");

	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	st1.push(50);

	std::cout << st1.peek(4) << std::endl;
	//std::cout << st1.pop() << std::endl;
	//std::cout << "The top value: " << st1.stackTop() << std::endl;


//	st1.display();
}




void print(std::string str1)
{
	std::cout << str1 << std::endl;
}