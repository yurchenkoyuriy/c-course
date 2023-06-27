#include <iostream>

int main()
{
    // Part 1 - Maximum
    std::cout << "Part 1 - Maximum" << std::endl;
    int a{};
    int b{};
    int c{};
    int max{};
     
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter third number: ";
    std::cin >> c;

    if (a > b && a > c)
    {
        max = a;
    }
    else if (b > a && b > c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    std::cout << "Maximum: " << max << std::endl;

    // Part 2 - Minimum
    std::cout << "Part 2 - Minimum" << std::endl;
    int num1{};
    int num2{};
    
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    int min = (num1 < num2) ? num1 : num2;

    std::cout << "Minimum: " << min << std::endl;

    // Part 3 - Multiple of 5 and 11 (55)
    std::cout << "Part 3 - Multiple of 55" << std::endl;
    int number{};    

    std::cout << "Enter number: ";
    std::cin >> number;
    
    if (number % 55 == 0) {
        std::cout << "Multiple" << std::endl;
    }
    else
    {
        std::cout << "No multiple" << std::endl;
    }

    // Part 4 - Angles of a triangle
    std::cout << "Part 4 - Angles of a triangle" << std::endl;
    int angel1{};
    int angel2{};
    int angel3{};

    std::cout << "Enter first angel: ";
    std::cin >> angel1;
    std::cout << "Enter second angel: ";
    std::cin >> angel2;
    std::cout << "Enter third angel: ";
    std::cin >> angel3;

    if ((angel1 + angel2 + angel3) == 180) {
        std::cout << "This is triangle" << std::endl;
    } 
    else
    {
        std::cout << "This isn't triangle" << std::endl;
    }

    // Part 5 - Enum Months
    std::cout << "Part 5 - Enum Months" << std::endl;
    enum class Month {
        january = 1,
        february = 2,
        march = 3,
        april = 4,
        may = 5,
        june = 6,
        july = 7,
        august = 8,
        september = 9,
        october = 10,
        november = 11,
        december = 12
    };
    int month{};

    std::cout << "Enter month number: ";
    std::cin >> month;

    switch (month)
    {
        case int(Month::january):
            std::cout << "january" << std::endl;
            break;
        case int(Month::february):
            std::cout << "february" << std::endl;
            break;
        case int(Month::march):
            std::cout << "march" << std::endl;
            break;
        case int(Month::april) :
            std::cout << "april" << std::endl;
            break;
        case int(Month::may) :
            std::cout << "may" << std::endl;
            break;
        case int(Month::june):
            std::cout << "june" << std::endl;
            break;
        case int(Month::july) :
            std::cout << "july" << std::endl;
            break;
        case int(Month::august) :
            std::cout << "august" << std::endl;
            break;
        case int(Month::september) :
            std::cout << "september" << std::endl;
            break;
        case int(Month::october) :
            std::cout << "october" << std::endl;
            break;
        case int(Month::november) :
            std::cout << "november" << std::endl;
            break;
        case int(Month::december) :
            std::cout << "december" << std::endl;
            break;
        default:
            std::cout << "Wrong month number" << std::endl;
    }

    // Part 6 - Seasons
    std::cout << "Part 6 - Seasons" << std::endl;

    int numMonth{};

    std::cout << "Enter month number: ";
    std::cin >> numMonth;

    if (numMonth < 1 && numMonth > 12) {
        std::cout << "Incorrect  month" << std::endl;
    }

    switch ((numMonth - 1) / 3) // Season part from 0 - 3 (numMonth-1 help cast to 0-11)
    {
    case 1:
        std::cout << "Spring" << std::endl;
        break;
    case 2:
        std::cout << "Summer" << std::endl;
        break;
    case 3:
        std::cout << "Autumn" << std::endl;
        break;    
    default:
        std::cout << "Winter" << std::endl;
    }
}
