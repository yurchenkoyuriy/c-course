#include <iostream>
#include "MathFunctions.h"

void counting(int count)
{
    int number{};
    int positive{};
    int negative{};
    int zeroes{};

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter your number(s): " << std::endl;
        std::cin >> number;

        if (number > 0)
        {
            positive++;
        }
        else if (number < 0)
        {
            negative++;
        }
    }

    zeroes = count - (positive + negative);

    std::cout << "Number of positive numbers: " << positive << std::endl;
    std::cout << "Number of negative numbers: " << negative << std::endl;
    std::cout << "Number of zeros: " << zeroes << std::endl;
}

int factorial(int count) {
    int factorial{ 1 };
    
    if (count == 1 || count == 0)
    {
        return 1;
    }

    do
    {
        factorial *= count;
        count--;
    } while (count != 0);

    return factorial;
}

int factorialRecursion(int count) {
    int factorial{};
    factorial = (count == 1 || count == 0) ? 1 : factorialRecursion(count - 1) * count;
    return factorial;
}

void printNaturalNumbersAscending(int count)
{
    for (int i = 1; i <= count; i++)
    {
        std::cout << i << ' ';
    }
}

void printNaturalNumbersDescending(int count)
{
    do
    {
        std::cout << count << ' ';
        count--;
    } while (count != 0);
}

void printNaturalNumbersAscendingRecursion(int count)
{
    if (count == 0)
    {
        return;
    }

    printNaturalNumbersAscendingRecursion(count - 1);
    std::cout << count << ' ';
}

void printNaturalNumbersDescendingRecursion(int count)
{
    if (count == 0)
    {
        return;
    }

    std::cout << count << ' ';
    printNaturalNumbersDescendingRecursion(count - 1);
}