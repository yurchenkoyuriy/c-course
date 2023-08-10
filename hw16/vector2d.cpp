#include "vector2d.h"


Vector2d& Vector2d::operator=(Vector2d& vector)
{
    this->x = vector.x;
    this->y = vector.y;

    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) 
{
    this->x += secondVector.x;
    this->y += secondVector.y;

    return *this;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) 
{
    this->x -= secondVector.x;
    this->y -= secondVector.y;

    return *this;
}


Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

float Vector2d::operator()() const
{
    return static_cast<float>(std::sqrt(x * x + y * y));
}

float& Vector2d::operator[](int i)
{
    return (i == 0) ? x : y;
}

std::ostream& operator<<(std::ostream& out, const Vector2d& vector) {
    out << "{" << vector.x << "; " << vector.y << "}" << std::endl;
    return out;
};

std::istream& operator>>(std::istream& in, Vector2d& vector) {
    in >> vector.x >> vector.y;
    return in;
};
