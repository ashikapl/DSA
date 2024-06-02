// Write a function to find area of circle //

#include <iostream>
#include <cmath>
using namespace std;

float circleArea(int r)
{
    float result = M_PI * pow(r, 2);
    return result;
}

int main()
{
    int r;
    cout << "Enter the value: ";
    cin >> r;

    float area = circleArea(r);

    cout << "Area of circle is: " << area;

    return 0;
}