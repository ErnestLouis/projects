#pragma once
#include <iostream>

enum class Priority
{
	HIGH = 1,
	MEDIUM = 2,
	LOW = 3
};

enum class Element : char
{
	A = 'A',
	B = 'B',
	C = 'C',
	D = 'D',
	E = 'E',
	F = 'F',
}; 

template <typename Element>
auto as_char(Element const value)
-> typename std::underlying_type<Element>::type
{
	return static_cast<typename std::underlying_type<Element>::type>(value);
}

Element get_element();


class Priority_queue
{
	friend std::istream& operator>>(std::istream& is, Element& e);

	private:
		int size;
		int front,front1,front2;
		int rear,rear1,rear2;
		Element* Q1; //for creating a n array size
		Element* Q2; //for creating a n array size
		Element* Q3; //for creating a n array size

	public:
		Priority_queue();
		Priority_queue(int size);
		//Priority_queue(int size, int num_of_queues);

		void enqueue(Element ele, Priority level);
		void display();
		int dequeue();
};

//Priority get_num(Priority num);

inline std::istream& operator>>(std::istream& is, Element& e)
{
			is >> e;
			return is;
}