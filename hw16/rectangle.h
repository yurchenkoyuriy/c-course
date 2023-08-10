class Rectangle
{
public:
    Rectangle() 
    {
        rectangleCount++;
    }
    Rectangle(float length_arg, float height_arg) :
        length(length_arg), height(height_arg)
    {
        rectangleCount++;
    }

    ~Rectangle() 
    {
        rectangleCount--;
    }

    float length = 0;
    float height = 0;

    float getArea();
    float getPerimeter();
    int getRectangleCount();
private:
    static int rectangleCount;
};