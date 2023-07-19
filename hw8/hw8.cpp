#include <iostream>
#include "MathFunctions.h"

int main()
{
    // Part 1
    int count{};
    std::cout << "Enter number of numbers for user input: " << count << std::endl;
    std::cin >> count;
    counting(count);

    // Part 2
    std::cout << "Enter number to calculate Factorial: " << count << std::endl;
    std::cin >> count;
    std::cout << "Factorial " << count <<" is: " << factorial(count) << std::endl;
    std::cout << "(Recursion)Factorial " << count << " is: " << factorialRecursion(count) << std::endl;

    // Part 3
    std::cout << "Enter how much output natural numbers: " << count << std::endl;
    std::cin >> count;

    std::cout << "First " << count << " natural numbers: " << std::endl;
    printNaturalNumbersAscending(count);

    std::cout << std::endl << "(Reverse)First " << count << " natural numbers: " << std::endl;
    printNaturalNumbersDescending(count);

    std::cout << std::endl << "(Recursion)First " << count << " natural numbers: " << std::endl;
    printNaturalNumbersAscendingRecursion(count);

    std::cout << std::endl << "(Recursion|Reverse)First " << count << " natural numbers: " << std::endl;
    printNaturalNumbersDescendingRecursion(count);
}
