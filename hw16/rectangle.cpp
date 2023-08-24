#include "Rectangle.h"

Rectangle::Rectangle()
{
    rectangleCount++;
}

Rectangle::Rectangle(float length_arg, float height_arg) :
    length(length_arg), height(height_arg)
{
    rectangleCount++;
}

Rectangle::~Rectangle()
{
    rectangleCount--;
}

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