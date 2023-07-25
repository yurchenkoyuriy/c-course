#include <iostream>
#include "HelpFunctions.h"
#include <ctype.h>

void translateArray(int numbers[], int size)
{	
    for (int i = 0; i < size; i++)
    {
        (numbers[i] > 0) ? numbers[i] *= 2 : numbers[i] = 0;
        std::cout << numbers[i] << ' ';
    }
}

void toUppercase(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (islower(str[i])) 
        {
            str[i] = toupper(str[i]);
        }        
        std::cout << str[i];
    }
}

bool isPalindrom(const char str[])
{
    int length = strlen(str) - 1;    

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] != str[length])
        {        
            return false;
            break;
        }
        length--;        
    }

	return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]))
        {
            const char symbol = tolower(str[i]);
            if (symbol == 'a' || symbol == 'o' || symbol == 'u' || symbol == 'i' || symbol == 'e' || symbol == 'y')
            {
                vowelsCount++;
            }
            else 
            {
                constonantsCount++;
            }            
        }
    }
}

bool isEqual(const char str1[], const char str2[])
{
    const int length = strlen(str1);

    if (length != strlen(str2))
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        } 
    }

    return true;
}