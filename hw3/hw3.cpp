#include <iostream>
#include <iomanip>

int main()
{
    // Part 1 - Change value of 2 input numbers
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
    
    std::cout << "integer 1: " << num1 << std::endl;
    std::cout << "integer 2: " << num2 << std::endl;

    // Part 2 - Init and work with double
    /*
        Створити та ініціалізувати змінну типу double, вивести значення змінної в консолі; вивести значення змінної приведене до типу int.
        (без символів після коми); Вивести число в рядок шириною 20 символів, вирівняти по правому краю, пусте місце заповнити символом ‘$’(дивись I / O manipulators)
    */

    double value = 23.345383487;

    std::cout << value << std::endl;
    std::cout << (int) value << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << value << std::endl;

    return 0;
}
