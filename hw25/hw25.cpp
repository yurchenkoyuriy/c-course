#include <iostream>
#include "vector2d.h"

struct Vector3d
{
    float x;
    float y;
    float z;
};

Vector3d crossProduct(const Vector3d& v1, const Vector3d& v2)
{
    Vector3d result;

    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;

    return result;
}

int main()
{
    Vector2d vector1;
    Vector2d vector2(-4.0f, -1.0f);
    Vector2d vector3(3.3f, 4.2f, 4.0f, 5.0f);

    std::cout << "Dot product: " << vector2.dotProduct(vector3) << std::endl;
    std::cout << "Negate: " << vector3.negate() << std::endl; 
    
    vector3.scale(4.3f, 2.6f);
    std::cout << "Scale: " << vector3 << std::endl;

    VectorRelativeState state = vector2.getRelativeState(vector3);
    Vector2d::printRelativeState(state);
    std::cout << std::endl;

    // crossProduct task
    Vector3d v1 = { 3.0f, 2.0f, 2.4f };
    Vector3d v2 = { 1.0f, 5.3f, 2.3f };

    Vector3d cross = crossProduct(v1, v2);

    std::cout << "Cross Product: (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;
}
