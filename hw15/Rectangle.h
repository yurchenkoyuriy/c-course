class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(float length_arg, float height_arg) :
        length(length_arg), height(height_arg)
    {   
    }

    ~Rectangle() = default;

    float getArea() const;
    float getPerimeter() const;

private:
    float length = 0;
    float height = 0;
};