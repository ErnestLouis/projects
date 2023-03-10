#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int arr_size(int A[]);

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
	void insert_sort(T data);
	void append(T data);
	void reverse();
	void rec_reverse();

	T remove_duplicate();
	T remove(int index);
	T sum();
	T max();
	T min();
	T linear_search(T key);

	bool is_sort();
	bool has_loop();
	double avg();
	int length();
	int rec_length();

	LinkedList* concat(LinkedList<T>& arr2);
	LinkedList* merge(LinkedList<T>& arr2);



};




int main()
{
	int A[] = { 2,3,4,5};

	int num = 6;

	LinkedList link01(A, arr_size(A));

	link01.display();

	link01.insert_sort(num);

    link01.display();


	/*
	cout << " before append: \n";

	link01.display();

	std::cout << endl;

	link01.append(num);

	std::cout << "Appended " << num << " into last index \n";

	link01.display();

	*/


/*
	cout << " before insertion: \n";

	link01.display();

	std::cout << endl;

	link01.insert(5,num);

	std::cout << "Insert " << num << " into index 5: \n";

	link01.display();
*/






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
		new_node->data = Arr[i];
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
	Node<T>* p = first;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class T>
void LinkedList<T>::rec_display()
{
	static Node<T>* p = first;

	if (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
		rec_display();
	}


}

template<class T>
void LinkedList<T>::insert(int index, T data)
{
	Node<T>* new_node, *p = first;

	if (index < 0 || index > length())
	{
		return;
	}
	new_node = new Node<T>;
	new_node->data = data;
	new_node->next = NULL;

	if (index == 0)
	{
		new_node->next = first;
		first = new_node;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		new_node->next = p->next;
		p->next = new_node;
	}

}

template<class T>
void LinkedList<T>::append( T data)
{
	Node<T>* new_node, * p = first;
	int index = length() - 1;

	new_node = new Node<T>;
	new_node->data = data;
	new_node->next = NULL;

	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	new_node->next = p->next;
	p->next = new_node;

}

template<class T>
void LinkedList<T>::insert_sort(T data)
{
	Node<T>* new_node, * p = first, * q = NULL;

	new_node = new Node<T>;
	new_node->data = data;
	new_node->next = NULL;

	if (first == NULL)
	{
		first = new_node;
	}
	else
	{
		while (p && p->data < data)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			new_node->next = first;
			first = new_node;
		}
		else
		{
			new_node->next = q->next;
			q->next = new_node;
		}
	}
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
T LinkedList<T>::linear_search(T key)
{
	Node<T>* p = first;

	int i = 0;
	while (p)
	{
		if (key == p->data)
		{
			return i;
		}
		i++;
		p = p->next;
	}

	return NULL;
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
	Node<T>* p = first;
	int count = 0;

	while (p)
	{
		count++;
		p = p->next;
	}

	return count;
}

template<class T>
int LinkedList<T>::rec_length()
{
	static Node<T>* p = first;
	//int count = 0;

	if (p == 0)
	{
		return 0;
	}
	else
	{
		p = p->next;
		return rec_length() + 1;
	}
}

template<class T>
LinkedList<T>* LinkedList<T>::concat(LinkedList<T>& arr2)
{



}

template<class T>
LinkedList<T>* LinkedList<T>::merge(LinkedList<T>& arr2)
{



}

int arr_size(int A[])
{
	int j = 0;
	int* a = new int[100];

	for (int i = 0; i < 100; i++)
	{
		a[i] = NULL;
	}

	a[0] = A[0];

	while (A[j] > -100)
	{
		a[j] = A[j];
		j++;
	}
	delete[] a;


	return j;
}