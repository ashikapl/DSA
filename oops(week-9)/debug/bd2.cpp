#include <iostream>
using namespace std;

class Shape
{
public:
    double width, height;
    Shape(double w, double h)
    {
        this->width = w;
        this->height = h;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : Shape(w, h) {}
    double area()
    {
        return this->width * this->height;
    }
};

int main()
{
    Rectangle r(5, 4);
    cout << "Area of the rectangle is: " << r.area() << endl;
    return 0;
}