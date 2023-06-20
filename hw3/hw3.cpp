#include <iostream>

int main()
{
    // 1 - Change value of 2 input numbers 
    int num1;
    int num2;
    int temp;

    std::cout << "Enter integer 1: ";
    std::cin >> num1;    
    std::cout << "Enter integer 2: ";
    std::cin >> num2;
    
    temp = num1;
    num1 = num2;
    num2 = temp;
    
    std::cout << "integer 1: " << num1 << "\n";
    std::cout << "integer 2: " << num2 << "\n";

    return 0;
}
