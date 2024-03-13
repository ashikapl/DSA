#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual void display() = 0;
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        return length * width;
    }
    void display()
    {
        cout << "Rectangle with length " << length << " and width " << width << endl;
    }
};

int main()
{
    Shape *s = new Rectangle(5, 10);
    cout << "Area of rectangle is: " << s->area() << endl;
    s->display();
    delete s;
    return 0;
}