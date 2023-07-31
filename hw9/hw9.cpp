#include <iostream>
#include "HelpFunctions.h"

int main()
{
    // Part 1    
    const short int size = 10;
    int numbers[size];

    std::cout << "Enter " << size << " numbers of array: ";

    for (int i = 0; i < size; i++)
    {
        std::cin >> numbers[i];
    }

    translateArray(numbers, size);

    // Part 2
    char str[256];
    
    std::cout << std::endl << "Enter string: ";
    std::cin >> str;

    toUppercase(str);

    // Part 3
    char palindrom[256];

    std::cout << std::endl << "Enter string: ";
    std::cin >> palindrom;

    if (isPalindrom(palindrom))
    {
        std::cout << palindrom << " is palindrom!" << std::endl;
    }
    else 
    {
        std::cout << palindrom << " isn't palindrom!" << std::endl;
    }

    // Part 4
    char check_string[256];
    int vowelsCount{0};
    int constonantsCount{0};

    std::cout << "Enter string: ";
    std::cin >> check_string;

    parseStringLetters(check_string, vowelsCount, constonantsCount);
    std::cout << "Count of vowels: " << vowelsCount << std::endl;
    std::cout << "Count of consonants: " << constonantsCount << std::endl;
    
    // Part 5
    char str1[256];
    char str2[256];
    
    std::cout << "Enter first string: ";
    std::cin >> str1;
    std::cout << "Enter first string: ";
    std::cin >> str2;

    
    if (isEqual(str1, str2))
    {
        std::cout << "The strings are equal!";
    }
    else
    {
        std::cout << "The strings are not equal!";
    }
}
