#include <iostream>
#include <iomanip>

int main()
{
    // Time in game
    std::cout << std::setw(30) << std::setfill('*') << std::left << "Part 1 " << std::endl;
    std::cout << "Enter seconds: ";
    
    int seconds(0);
    
    std::cin >> seconds;

    int hours = seconds / (3600);
    int minutes = (seconds % 3600) / (60);
    seconds = seconds % 60;

    std::cout << hours << " hour " << minutes << " minutes " << seconds << " seconds " << std::endl;

    // 3 values
    std::cout << std::endl << std::setw(30) << std::setfill('*') << std::left << "Part 2 " << std::endl;

    int a(0);
    int b(0);
    int c(0);

    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter third number: ";
    std::cin >> c;

    int sum = a + b + c;

    std::cout << "Suma: " << sum << std::endl;
    std::cout << "Product: " << a * b * c << std::endl;
    std::cout << "Avg: " << sum / 3 << std::endl;
    std::cout << "A equal to B: " << (a == b) << std::endl;
    std::cout << "B equal to C: " << (b == c) << std::endl;

    // Bools
    std::cout << std::endl << std::setw(30) << std::setfill('*') << std::left << "Part 3 " << std::endl;

    int num1(0);
    int num2(0);

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    bool lessThan = num1 < num2;
    bool equal = num1 == num2;
    bool moreThan = num1 > num2;
    bool lessorEqual = num1 <= num2;

    std::cout << "lessThan: " << lessThan << std::endl;
    std::cout << "equal: " << equal << std::endl;
    std::cout << "moreThan: " << moreThan << std::endl;
    std::cout << "lessorEqual: " << lessorEqual << std::endl;

    // Rectangel
    std::cout << std::endl << std::setw(30) << std::setfill('*') << std::left << "Part 4 " << std::endl;

    int width(0);
    int height(0);

    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;

    int square = width * height;
    int length = (width + height) * 2;
    
    std::cout << "Square: " << square << std::endl;
    std::cout << "Length: " << length << std::endl;

    // Circle
    std::cout << std::endl << std::setw(30) << std::setfill('*') << std::left << "Part 5 " << std::endl;

    float p = 3.14;
    int radius(0);

    std::cout << "Enter circle radius: ";
    std::cin >> radius;
    
    float squareCircle = p * (radius * radius);
    float lengthCircle = 2 * p * radius;

    std::cout << "Square: " << squareCircle << std::endl;
    std::cout << "Length: " << lengthCircle << std::endl;
}
