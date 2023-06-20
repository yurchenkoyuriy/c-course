#include <iostream>
#include <iomanip>

int main()
{
    // Part 1 - Change value of 2 input numbers
    std::cout << "Part 1" << std::endl;

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
    
    std::cout << "Integer 1: " << num1 << std::endl;
    std::cout << "Integer 2: " << num2 << std::endl;

    // Part 2 - Init and work with double
    std::cout << std::endl << "Part 2" << std::endl;

    double value = 23.345383487;

    std::cout << "Double: " << value << std::endl;
    std::cout << "Double to Int: " << (int) value << std::endl;
    std::cout << "Format Double: " << std::setw(20) << std::right << std::setfill('$') << value << std::endl;

    // Part 3 - Format double
    std::cout << std::endl << "Part 3" << std::endl;

    double someValue = 2323.3453834871234;

    std::cout << "2 values after point: " << std::setprecision(2) << someValue << std::endl;
    std::cout << "5 values after point: " << std::setprecision(5) << someValue << std::endl;
    std::cout << "10 values after point: " << std::setprecision(10) << someValue << std::endl;
    std::cout << "2 values after point(e-notation): " << std::fixed << std::setprecision(2) << someValue << std::endl;
    std::cout << "5 values after point(e-notation): " << std::fixed << std::setprecision(5) << someValue << std::endl;
    std::cout << "10 values after point(e-notation): " << std::fixed << std::setprecision(10) << someValue << std::endl;

    // Part 4 - Enum WeekDay
    std::cout << std::endl << "Part 4" << std::endl;
    enum class WeekDay {
        monday = 1,
        tuesday = 2,
        wednesday = 3,
        thursday = 4,
        friday = 5,
        saturday = 6,
        sunday = 7
    };

    std::cout << int(WeekDay::monday) << std::endl;
    std::cout << int(WeekDay::tuesday) << std::endl;
    std::cout << int(WeekDay::wednesday) << std::endl;
    std::cout << int(WeekDay::thursday) << std::endl;
    std::cout << int(WeekDay::friday) << std::endl;
    std::cout << int(WeekDay::saturday) << std::endl;
    std::cout << int(WeekDay::sunday) << std::endl;
    
    // 5 - Bool to pretty output
    std::cout << std::endl << "Part 5" << std::endl;

    int number;
    
    std::cout << "Enter some number: ";
    std::cin >> number;

    bool flag = number;

    std::cout << "Bool value: " << std::boolalpha << flag;

    return 0;
}
