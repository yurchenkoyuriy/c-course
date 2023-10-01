#pragma once
#include <iostream>

enum class VectorRelativeState
{
    Identical,
    CoDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d
{
public:
    Vector2d();
    Vector2d(float x1, float y1);
    Vector2d(float x0, float y0, float x1, float y1);
    ~Vector2d();

    Vector2d& operator=(Vector2d& vector);
    Vector2d operator+(const Vector2d& secondVector);
    Vector2d operator-(const Vector2d& secondVector);

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
    
    float operator()() const;
    float& operator[](int i);
    
    friend std::ostream& operator<<(std::ostream& out, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& in, Vector2d& vector);
        
    float dotProduct(const Vector2d& other) const;
    Vector2d negate() const;
    void scale(float factorX, float factorY);
    VectorRelativeState getRelativeState(const Vector2d& other) const;    
    static void printRelativeState(VectorRelativeState state);       

private:
    float m_x;
    float m_y;
};