#include <iostream>
#include <cmath>

class Vector2d
{
public:
    Vector2d();
    Vector2d(float x_arg, float y_arg);
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

private:
    float x;
    float y;    
};