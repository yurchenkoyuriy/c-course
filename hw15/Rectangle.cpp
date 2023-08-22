#include "Rectangle.h"

float Rectangle::getArea() const
{
    return length * height;
}

float Rectangle::getPerimeter() const
{
    return (length + height) * 2;
}