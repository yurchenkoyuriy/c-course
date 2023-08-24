class Rectangle
{
public:
    Rectangle();
    Rectangle(float length_arg, float height_arg);
    ~Rectangle();

    float getArea();
    float getPerimeter();
    int getRectangleCount();
private:
    static int rectangleCount;
    float length = 0;
    float height = 0;
};