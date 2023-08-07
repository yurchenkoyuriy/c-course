class Rectangle
{
public:
    Rectangle() {}
    Rectangle(float length_arg, float height_arg) :
        length(length_arg), height(height_arg)
    {   
    }

    ~Rectangle() = default;

    float length = 0;
    float height = 0;

    float getArea();
    float getPerimeter();
};