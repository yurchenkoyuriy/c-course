#include <iostream>
#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray()  
{
	size = 100;
	int_array = new int[size];
}

DynamicIntArray::DynamicIntArray(std::size_t size_arg)
{	
	size = (size_arg > 0) ? size_arg : 0;
	int_array = new int[size];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) 
{
	size = other.size;
	int_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_array[i] = other.int_array[i];
	}
}

DynamicIntArray::~DynamicIntArray() 
{
	delete[] int_array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) 
{
	if (&other == this)
		return *this;

	size = other.size;	
	delete[] int_array;
	int_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_array[i] = other.int_array[i];
	}

	return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
	if (index >= size)
	{
		std::cerr << "operator[] index: " << index << " is out of range!";
	}

	return int_array[index];
}

void DynamicIntArray::setSize(std::size_t newSize) 
{
	if (newSize > 0)
	{
		int* tempArray = new int[newSize];
		for (int i = 0; i < newSize; i++)
		{
			tempArray[i] = int_array[i];
		}

		if (size < newSize)
		{
			for (int i = size; i < newSize; i++)
			{
				tempArray[i] = 0;
			}
		}

		size = newSize;
		int_array = tempArray;
	}	
}

std::size_t DynamicIntArray::getSize() const
{
	return size;
}

void DynamicIntArray::clear() 
{
	delete[] int_array;	
	size = 0;	
	int_array = nullptr;
}

void DynamicIntArray::push_back(int element) 
{	
	setSize(size+1);
	int_array[size-1] = element;
}
