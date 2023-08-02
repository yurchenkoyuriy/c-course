#include <iostream>
#include "ArrayFunctions.h"

int main()
{    
    const int ROWS = 5;
    const int COLUMNS = 5;
    const int LENGTH = 10;
    int elem = 5;    
    
    int arr[LENGTH] = { 5, 2, 0, 6, 10, 15, 9, 1, 3, 8 };    
    int arr_2d[ROWS][COLUMNS] = {
        {1, 2, 3, 4, 5 },
        {6, 7, 8, 9, 10 },
        {11, 12, 13, 14, 15 },
        {16, 17, 18, 19, 20 },
        {21, 22, 23, 24, 25 }
    };

    // Part 1    
    if (linearSearch(arr_2d, ROWS, COLUMNS, elem))
    {
        std::cout << "Element " << elem << " was found!" << std::endl;
    }
    else
    {
        std::cout << "Element " << elem << " wasn't found!" << std::endl;
    }

    // Part 2    
    if (isSorted(arr, LENGTH, SortingDirection::ascending))
    {
        std::cout << "Array sorted" << std::endl;
    } 
    else
    {
        std::cout << "Array not sorted" << std::endl;
    }

    // Part 3
    arrayTraversal(arr_2d, ROWS, COLUMNS);
    arrayTraversalSecondVersion(arr_2d, ROWS, COLUMNS);
}
