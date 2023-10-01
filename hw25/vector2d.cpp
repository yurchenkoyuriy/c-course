#include "vector2d.h"

Vector2d::Vector2d() : m_x(0.0f), m_y(0.0f) {}

Vector2d::Vector2d(float x, float y) : m_x(x), m_y(y) {}

Vector2d::Vector2d(float x_0, float y_0, float x_1, float y_1) : m_x(x_1 - x_0), m_y(y_1 - y_0) {}

Vector2d::~Vector2d() = default;

Vector2d& Vector2d::operator=(Vector2d& vector)
{
    if (&vector == this)
    {
        return *this;
    }

    this->m_x = vector.m_x;
    this->m_y = vector.m_y;

    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector)
{
    this->m_x += secondVector.m_x;
    this->m_y += secondVector.m_y;
    
    return *this;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector)
{
    this->m_x -= secondVector.m_x;
    this->m_y -= secondVector.m_y;
    
    return *this;
}


Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    Vector2d tempVector(leftVector);
    return tempVector + rightVector;
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    Vector2d tempVector(leftVector);
    return tempVector - rightVector;
}

float Vector2d::operator()() const
{
    return static_cast<float>(std::sqrt(m_x * m_x + m_y * m_y));
}

float& Vector2d::operator[](int i)
{
    return (i == 0) ? m_x : m_y;
}

std::ostream& operator<<(std::ostream& out, const Vector2d& vector) {
    out << "{" << vector.m_x << "; " << vector.m_y << "}" << std::endl;
    return out;
};

std::istream& operator>>(std::istream& in, Vector2d& vector) {
    in >> vector.m_x >> vector.m_y;
    return in;
};

float Vector2d::dotProduct(const Vector2d& other) const
{    
    return m_x * other.m_x + m_y * other.m_y;    
}

Vector2d Vector2d::negate() const
{
    return Vector2d(-m_x, -m_y);
}

void Vector2d::scale(float factorX, float factorY)
{
    m_x *= factorX;
    m_y *= factorY;
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
    float dot = dotProduct(other);

    if (dot == 0)
    {
        return VectorRelativeState::RightAngle;
    }
    else if (dot > 0)
    {
        if ((*this)() == other())
        {
            return VectorRelativeState::Identical;
        }
        else if ((*this)() == -other())
        {
            return VectorRelativeState::OppositeDirected;
        }
        else if (m_x / other.m_x == m_y / other.m_y)
        {
            return VectorRelativeState::CoDirected;
        }
        else
        {
            return VectorRelativeState::AcuteAngle;
        }
    }
    else
    {
        return VectorRelativeState::ObtuseAngle;
    }
}

void Vector2d::printRelativeState(VectorRelativeState state) {
    switch (state) {
        case VectorRelativeState::Identical:
            std::cout << "Identical";
            break;
        case VectorRelativeState::CoDirected:
            std::cout << "Co-Directed";
            break;
        case VectorRelativeState::OppositeDirected:
            std::cout << "Opposite Directed";
            break;
        case VectorRelativeState::AcuteAngle:
            std::cout << "Acute Angle";
            break;
        case VectorRelativeState::ObtuseAngle:
            std::cout << "Obtuse Angle";
            break;
        case VectorRelativeState::RightAngle:
            std::cout << "Right Angle";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
}