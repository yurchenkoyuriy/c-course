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
    bool check = true;
    int length = strlen(str) - 1;    

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] != str[length])
        {        
            check = false;
            break;
        }
        length--;        
    }

	return check;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
    const char letters[6] = { 'a','o','u','i','e','y' };
    
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(letters); j++)
        {
            if (tolower(str[i]) == letters[j])
            {
                vowelsCount++;
                break;
            }
        }
    }

    constonantsCount = strlen(str) - vowelsCount;
}

bool isEqual(const char str1[], const char str2[])
{
    if (strlen(str1) != strlen(str2))
        return false;

    const int diff = 32;

    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            int temp_diff = int(str1[i]) - int(str2[i]);
            temp_diff *= (temp_diff < 0) ? -1 : 1;

            if (temp_diff != diff)
            {                
                return false;                
            }            
        } 
    }

    return true;
}