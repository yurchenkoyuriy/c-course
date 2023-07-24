#include "HomeFunctions.h"
#include <iostream>

void swap(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum)
{
	if (arrSize <= 0)
	{
		return false;
	}

	for (int i = 0; i < arrSize; i++)
	{
		sum += arr[i];		
	}

	return true;
}

bool find(const int* arr, int size, int elem)
{	
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == elem)
		{
			return true;
		}
	}

	return false;
}