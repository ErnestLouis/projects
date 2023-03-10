#include <iostream>

template <class Type>
class Node
{
public:
	Type data;
	Node* next;
};


template <class T>
class LinkedList
{
private:

	Node<T>*  first;

public:

	LinkedList();
	LinkedList(T A[], int num_of_elements);
	~LinkedList();

	void display();
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
LinkedList<T>::LinkedList()
{
	first = NULL;
}


template<class T>
LinkedList<T>::LinkedList(T Arr[], int num_of_elements)
{
	Node<T>* new_node, * last;
	first = new Node<T>;
	first->data = Arr[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < num_of_elements; i++)
	{
		new_node = new Node<T>;
		new_node->data = Arr[0];
		new_node->next = NULL;
		last->next = new_node;
		last = new_node;
	}

}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
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

