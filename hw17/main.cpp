#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray newArray(5);    
    newArray[0] = 1;
    newArray[1] = 2;
    newArray[2] = 3;

    std::cout << newArray[1] << std::endl;
    std::cout << newArray.getSize() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    DynamicIntArray newArray2(newArray);
    newArray2[1] = 4;

    std::cout << newArray2[0] << std::endl;
    std::cout << newArray2[2] << std::endl;
    std::cout << newArray2.getSize() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    DynamicIntArray newArray3(newArray);
    newArray3 = newArray2;

    std::cout << newArray3[1] << std::endl;
    std::cout << newArray3[2] << std::endl;
    std::cout << newArray3.getSize() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    newArray3.clear();
    std::cout << newArray3[0] << std::endl;
    std::cout << newArray3.getSize() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    newArray.setSize(1);
    std::cout << newArray[0] << std::endl;
    std::cout << newArray[1] << std::endl;
    std::cout << newArray.getSize() << std::endl;
    newArray.push_back(10);
    std::cout << newArray[0] << std::endl;
    std::cout << newArray[1] << std::endl;
    std::cout << newArray.getSize() << std::endl;

    std::cout << "----------------------------------" << std::endl;

    DynamicIntArray newTestArray(3);
    newTestArray[0] = 1;
    newTestArray[1] = 2;
    newTestArray[2] = 3;

    for (int i = 0; i < newTestArray.getSize(); i++)
    {
        std::cout << newTestArray[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << newTestArray.getSize() << std::endl;
    newTestArray.setSize(10);
    std::cout << newTestArray.getSize() << std::endl;
    newTestArray.push_back(2);
    newTestArray.push_back(12);
    newTestArray.push_back(13);
    for (int i = 0; i < newTestArray.getSize(); i++)
    {
        std::cout << newTestArray[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << newTestArray.getSize() << std::endl;

}