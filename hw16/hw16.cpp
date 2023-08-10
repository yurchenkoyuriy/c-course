#include <iostream>
#include "rectangle.h"
#include "vector2d.h"

int main()
{
    // Tassk 1
    Rectangle rec(2,3);
    {
        Rectangle rec1(2, 4);
        {
            Rectangle rec2(3, 3);
            std::cout << "Rectangle count: " << rec.getRectangleCount() << std::endl;
        }
        std::cout << "Rectangle count: " << rec.getRectangleCount() << std::endl;
    }
    std::cout << "Rectangle count: " << rec.getRectangleCount() << std::endl;
    
    // Tassk 2
    Vector2d vector1(3.2f, 4.2f);
    Vector2d vector2(4.2f, 5.2f);
    Vector2d vector3;

    std::cout << "Vector: " << vector1;
    vector1 = vector2;
    std::cout << "Vector: " << vector1;
    vector1 + vector2;
    std::cout << "Vector: " << vector1;
    vector1 - vector2;
    std::cout << "Vector: " << vector1;
    std::cout << "Sum of three vectors: " << (vector1 + vector1 + vector1);
    std::cout << "Difference of three vectors: " << (vector2 - vector1 - vector1);    
    std::cout << "Length: " << vector1() << std::endl;
    std::cout << "Y: " << vector1[1] << std::endl;
    std::cout << vector3;
    std::cin >> vector3;
    std::cout << vector3;    
}
