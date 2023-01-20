// array_adt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Implemented Dynamic Array
//12-26-22

#include <iostream>
#include <algorithm>



template<class T>
class Array
{
private:
	T* A;
	int size;
	int length;
public:
	Array()
	{
		size = 10;
		length = 0;
		A = new T[size];
	}
	Array(int size)
	{
		this->size = size;
		length = 0;
		A = new T[size];
	}


	void display();

	void insert(int index, T x);

	void append(T x);

	void reverse();

	void shift_right();

	void shift_left();

	void rotate_right();

	void rotate_left();

	void insert_sort(int x);

	void rearrange();

	bool is_sorted();

	int sum();

	float avg();

	Array* merge(Array<T>& arr2);

	T remove(int index);

	T binary_search(T key);

	T rbinary_search(int l, int h, T key);

	T linear_search(T key);

	T max();

	T min();

	void set(int index, T x);

	T get(int index);

	~Array()
	{
		delete[] A;
	}
};

void clear_screen()
{
	system("cls"); //clears windows screen
}

void wait_for_keypress()
{
	system("pause");//for windows only!

}


int main()
{

	Array<int> arr;

	arr.append(7);
	arr.append(9);
	arr.append(11);

	Array<int> arr2;

	arr2.append(6);
	arr2.append(10);
	arr2.append(12);


	//arr.remove(1);



	Array<int>* arr3;

	arr3 = arr.merge(arr2);

	arr3->display();
	/*

	bool is_true{ false };

	do {

		int i = 0;
		if (i < 100)
		{
			arr.display();
			arr.rotate_right();
		}

		wait_for_keypress();
		clear_screen();


	} while (!is_true);

	*/
	/*
	int num = 6;

	//arr.insert(0, 1);
	//arr.insert(1, 7);
	//arr.insert(2, 7);
	//std::cout << "Before removal." << std::endl;
	arr.display();

	//std::cout << "The location of "<< num <<" in the array is: " << std::endl;
	//std::cout << arr.binary_search(num) << std::endl;
	//std::cout << arr.linear_search(num) << std::endl;
	//std::cout << arr.rbinary_search(0,6,num) << std::endl;

	//arr.set(0, 12);
	//std::cout << arr.avg() <<std::endl;
	arr.rotate_right();
	arr.display();


	//std::cout << "After removal." << std::endl;
	//arr.display();
	*/
	//quick program

	/*
	Array<char> welcome(25);

	welcome.append('W');
	welcome.append('e');
	welcome.append('l');
	welcome.append('c');
	welcome.append('o');
	welcome.append('m');
	welcome.append('e');
	welcome.append('!');
	welcome.append('.');
	welcome.append('.');
	welcome.append('.');
	welcome.append('\0');

	bool is_true{ false };

	do {

		int i = 0;
		if (i < 100)
		{
			welcome.display();
			welcome.rotate_right();
		}

		//wait_for_keypress();
		for (int i = 0; i < 100000000; i++) {

		}
		clear_screen();


	} while (!is_true);

	*/


}

//display
template<class T>
void Array<T>::display()
{

	//std::cout << "Elements are: ";
	for (int i{ 0 }; i < length; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

//insert
template<class T>
void Array<T>::insert(int index, T x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (int i = length; i > index; i--)
		{
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}

//Delete
template<class T>
T Array<T>::remove(int index)
{
	T x = 0;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (int i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
	}
	return x;
}

//Append
template<class T>
void Array<T>::append(T x)
{
	if (length < size)
		A[length++] = x;
}

//Linear_Search
template <class T>
T Array<T>::linear_search(T key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == A[i]) //<------ Type the line of code that goes here
		{
			std::swap(A[i], A[0]);
			return i;
		}
	}
	return -1;
}

//Binary_Search
template <class T>
T Array<T>::binary_search(T key)
{
	int h = length - 1;    //<------ Type the line of code that goes here
	int l = 0;

	while (l <= h)
	{
		int mid = (h + l) / 2;
		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}

//RBinary_Search
template <class T>
T Array<T>::rbinary_search(int l, int h, T key)     //<------ Type the line of code that goes here
{
	//h = length - 1;
	//l = 0;

	int mid = 0;
	if (l <= h)
	{
		mid = (h + l) / 2;
		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid])
		{
			return rbinary_search(l, mid - 1, key);
		}
		else
		{
			return rbinary_search(mid + 1, h, key);
		}
	}
	return -1;
}


//get
template <class T>
T Array<T>::get(int index) //<---------- What is the Array member function name?
{
	if (index >= 0 && index < length)
	{
		return A[index];
	}

	return -1;
}


//set
template <class T>
void Array<T>::set(int index, T x)
{
	if (index >= 0 && index < length)
	{
		A[index] = x;
	}
}

//Max
template <class T>
T Array<T>::max()
{
	int big = A[0];    //<------ Type the line of code that goes here

	for (int i{}; i < length; i++)
	{
		if (A[i] > big)
		{
			big = A[i];
		}
	}
	return big;
}

//Min
template <class T>
T Array<T>::min()
{
	int small = A[0];

	for (int i{}; i < length; i++)
	{
		if (A[i] < small)
		{
			small = A[i];
		}
	}
	return small;
}

//sum
template <class T>
int Array<T>::sum()
{
	int s = 0;
	for (int i = 0; i < length; i++)
	{
		s += A[i];
	}
	return s;
}

template <class T>
float Array<T>::avg()
{
	return (float)sum() / length;
}

template <class T>
void Array<T>::reverse()
{

	for (int i = 0, j = (length - 1); i < j; i++, j--)
	{
		std::swap(A[i], A[j]);
	}
}

template <class T>
void Array<T>::shift_right()
{
	int zero{ 0 };

	for (int i = length - 1; i >= 0; i--)  //<------ Type the line of code that goes here
	{
		A[i + 1] = A[i];
	}

	A[0] = zero;

}

template <class T>
void Array<T>::shift_left()
{
	int zero{ 0 };

	for (int i = 0; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}

	A[length - 1] = zero;

}


template <class T>
void Array<T>::rotate_right()
{
	int lost_var = A[length - 1];


	for (int i = length - 1; i >= 0; i--)
	{
		A[i + 1] = A[i];
	}

	A[0] = lost_var;

}

template <class T>
void Array<T>::rotate_left()
{
	int lost_var = A[0];

	for (int i = 0; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}

	A[length - 1] = lost_var;

}
template <class T>
bool Array<T>::is_sorted()
{
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1]) //<------ Type the line of code that goes here
		{
			return false;
		}

		return true;
	}
}

template <class T>
void Array<T>::insert_sort(int x)
{
	int i = length - 1;
	if (length == size)  //<------ Type the line of code that goes here
	{
		return;
	}
	while (i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

template<class T>
void Array<T>::rearrange()
{
	int i = 0;
	int j = length - 1;

	while (i < j)
	{
		while (A[i] < 0) i++;   //<------ Type the line of code that goes here
		while (A[j] >= 0) j--;
		if (i < j)
		{
			std::swap(A[i], A[j]);
		}
	}

}
template<class T>
Array<T>* Array<T>::merge(Array<T>& arr2)
{
	int i, j, k;
	i = j = k = 0;

	Array<T>* arr3 = new Array<T>(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else
		{
			arr3->A[k++] = arr2.A[j++];
		}


	}
	for (; i < length; i++)
	{
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++)
	{
		arr3->A[k++] = arr2.A[j];
	}
	arr3->length = k; //k equals length + arr2.length

	return arr3;
}

//<------ Type the line of code that goes here
//<---------- What is the Array member function name?