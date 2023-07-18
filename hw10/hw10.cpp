#include <iostream>
#include "HomeFunctions.h"

int main()
{
    // Part 1
    int a{1};
    int b{2};
        
    swap(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int* c = &a;
    int* d = &b;

    swap(c, d);

    std::cout << *c << std::endl;
    std::cout << *d << std::endl;

    // Part 2

    const short int sizeArr = 5;
    double arr[sizeArr];
    double sum{};

    std::cout << "Enter " << sizeArr << " numbers of array: ";

    for (int i = 0; i < sizeArr; i++)
    {
        std::cin >> arr[i];
    }
    
    if (calculateSum(arr, sizeArr, sum))
    {
        std::cout << "Suma of elements is: " << sum << std::endl;
    }
    
    // Part 3

    const short int size = 5;
    int arr_find[size];
    int elem{};

    std::cout << "Enter element we want to found: ";
    std::cin >> elem;

    std::cout << "Enter " << size << " numbers of array: ";

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr_find[i];
    }

    if (find(arr_find, size, elem))
    {
        std::cout << "Element " << elem << " was found!";
    } 
    else 
    {
        std::cout << "Element " << elem << " not found!";
    }
}
