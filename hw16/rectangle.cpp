#include "Rectangle.h"

float Rectangle::getArea()
{
    return length * height;
}

float Rectangle::getPerimeter()
{
    return (length + height) * 2;
}

int Rectangle::getRectangleCount()
{
    return rectangleCount;
}

int Rectangle::rectangleCount = 0;