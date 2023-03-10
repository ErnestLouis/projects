#include <iostream>

template <class T>
class Node
{
public:
	T data;
	Node* next;
};


template <class T>
class LinkedList
{
private:
	Node* first;

public:
	Linkedlist()
	{
		first = NULL;
	}

	LinkedList(T A[], int num_of_elements);
	~LinkedList();

	void display();
	void rec_display();
	void rec_display();
	void insert(int index, T data);
	void insert_sort();
	void reverse();
	void rec_reverse();

	T remove_duplicate();
	T remove(int index);
	T sum();
	T max();
	T min();
	T linear_search();

	bool is_sort();
	bool has_loop();
	double avg();
	int length();

	LinkedList* concat(LinkedList<T>& arr2);
	LinkedList* merge(LinkedList<T>& arr2);
};



int main()
{
	int A[] = { 2,4,6,8,10 };

	LinkedList Link01(A, 5);






}



//Linked_list Implentations


template<class T>
LinkedList<T>::LinkedList(T A[], int num_of_elements)
{

}

template<class T>
LinkedList<T>::~LinkedList()
{



}

template<class T>
void LinkedList<T>::display()
{



}

template<class T>
void LinkedList<T>::rec_display()
{



}

template<class T>
void LinkedList<T>::rec_display()
{



}

template<class T>
void LinkedList<T>::insert(int index, T data)
{



}

template<class T>
void LinkedList<T>::insert_sort()
{



}

template<class T>
void LinkedList<T>::reverse()
{



}

template<class T>
void LinkedList<T>::rec_reverse()
{



}

template<class T>
T LinkedList<T>::remove_duplicate()
{



}

template<class T>
T LinkedList<T>::remove(int index)
{



}

template<class T>
T LinkedList<T>::sum()
{



}

template<class T>
T LinkedList<T>::max()
{



}

template<class T>
T LinkedList<T>::min()
{



}

template<class T>
T LinkedList<T>::linear_search()
{



}

template<class T>
bool LinkedList<T>::is_sort()
{



}

template<class T>
bool LinkedList<T>::has_loop()
{



}

template<class T>
double LinkedList<T>::avg()
{



}

template<class T>
int LinkedList<T>::length()
{



}

template<class T>
LinkedList<T>* LinkedList<T>::concat(LinkedList<T>& arr2)
{



}

template<class T>
LinkedList<T>* LinkedList<T>::merge(LinkedList<T>& arr2)
{



}