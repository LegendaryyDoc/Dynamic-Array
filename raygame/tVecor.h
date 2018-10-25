#pragma once
#include "raylib.h"
#include "iostream"

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};


/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/


template<typename T>
inline tVector<T>::tVector()
{
	arr = new T[5];
	arrCapacity = 5;
	arrSize = 0;
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] arr;
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (arrCapacity > newCapacity)
	{
		return;
	}
	T *temp = new T[newCapacity];
	for (size_t i = 0; i < arrSize; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;

	arr = temp;
	arrCapacity = newCapacity;
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity)
	{
		reserve(arrCapacity * GROWTH_FACTOR);
	}

	arr[arrSize] = value;
	++arrSize;
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrCapacity--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	// TODO: insert return statement here
	std::cout <<"Index: " << arr[index] << std::endl;

	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	std::cout << "Size: " << arrSize << std::endl;

	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	std::cout <<"Capacity: " << arrCapacity << std::endl;

	return arrCapacity;
}
