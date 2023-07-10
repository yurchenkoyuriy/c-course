#include <iostream>
#include <iomanip>
#include <ctype.h>

int main()
{
    // Part 1 - Arithmetic progression
    std::cout << "Part 1 - Arithmetic progression" << std::endl;
    int a{};
    int d{};
    int n{};

    std::cout << "Enter first element: ";
    std::cin >> a;
    std::cout << "Step of arithmetic progression: ";
    std::cin >> d;
    std::cout << "Size of arithmetic progression: ";
    std::cin >> n;

    do {       
        std::cout << a << " ";
        n--;
        a += d;
    } 
    while (n > 0);

    std::cout << std::endl;

    // Part 2 - Fibonacci
    std::cout << "Part 2 - Fibonacci" << std::endl;
    int number{};        

    unsigned long olderNumber = 0;
    unsigned long oldNumber =  1;
    unsigned long fibonacci = 1;    
    unsigned long temp = 0;

    std::cout << "Enter the number of the Fibonacci sequence: ";
    std::cin >> number;
    
    for (int i = 2; i <= number; i++) {
        temp = olderNumber + oldNumber;
        olderNumber = oldNumber;
        oldNumber = temp;        

        fibonacci += temp;
    }

    std::cout << "Fibonacci: " << fibonacci << std::endl;

    // Part 3 - Factorial
    std::cout << "Part 3 - Factorial" << std::endl;
    int num{};
    int factorial(1);

    std::cout << "Enter the number: ";
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    std::cout << "Factorial number " << num << " is: " << factorial << std::endl;

    // Part 4 - Figures
    std::cout << "Part 4 - Figures" << std::endl;
    int width{};
    int height{};

    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;

    for (int i = width; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 1; i <= width; i++) {
        for (int j= 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    int indent(1);
    for (int i = 1; i <= width; i++) {
        std::cout << std::setw(indent) << std::setfill(' ');
        for (int j = 1; j <= height; j++) {
            std::cout << "w";
        }
        indent++;
        std::cout << std::endl;
    }

    std::cout << std::endl;

    bool flag{};
    bool lineFlag = 1;
    for (int i = 1; i <= width; i++) {
        flag = lineFlag;
        for (int j = 1; j <= i; j++) {
            std::cout << flag;
            flag = !flag;
        }
        lineFlag = !lineFlag;
        std::cout << std::endl;
    }

    // Part 5 - Program 
    std::cout << "Part 5 - Program" << std::endl;    
    int sum{};
    char symbol{};

    do {                
        std::cout << "Enter some char symbol: ";
        std::cin >> symbol;

        if (ispunct(symbol)) {
            std::cout << "This character is not processed by the program" << std::endl;
            continue;
        } else if (islower(symbol)) {
            symbol = toupper(symbol);
            std::cout << "To upper: " << symbol << std::endl;
        } else if (isdigit(symbol)) {
            sum += (int)symbol - '0'; // ASCII code of 48
            std::cout << "Summa: " << sum << std::endl;
        }
    } while (symbol != '.');
}