#include <iostream>
#include "ArrayFunctions.h"

bool linearSearch(const int arr[][SIZE], int rows, int cols, int elem)
{	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == elem)
			{
				return true;
				break;
			}
		}
	}

	return false;
}

bool isSorted(const int* arr, int size, SortingDirection direction)
{	
	int next = 1;

	for (int i = 0; i < size - 1; i++)
	{
		if (((int)direction && arr[i] > arr[next]) || (!(int)direction && arr[i] < arr[next]))
		{
			return false;
		} 		
		next++;
	}
	return true;

}

void arrayTraversal(const int arr[][SIZE], int rows, int cols)
{
	for (int j = cols - 1; j >= 0; j--)
	{
		for (int i = 0; i < rows; i++)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void arrayTraversalSecondVersion(const int arr[][SIZE], int rows, int cols)
{
	bool flag = true;

	for (int i = rows-1; i >= 0 ; i--)
	{
		if (flag)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << arr[i][j] << ' ';
			}
		}
		else
		{
			for (int j = cols - 1; j >= 0; j--)
			{
				std::cout << arr[i][j] << ' ';
			}
		}		
		std::cout << std::endl;
		flag = !flag;		
	}
}