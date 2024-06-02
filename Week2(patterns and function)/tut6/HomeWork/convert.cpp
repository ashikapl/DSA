// Convert Celsius into Fahrenheit //

#include <iostream>
using namespace std;

float convertFahrenheit(float c)
{
    float F = (c * 9 / 5) + 32;
    return F;
}

float convertCelsius(float f)
{
    float C = (f - 32) * 5 / 9;
    return C;
}

int main()
{
    int c;
    cout << "Enter the value of Celsius: ";
    cin >> c;

    float fahrenheit = convertFahrenheit(c);

    cout << fahrenheit << endl;

    int f;
    cout << "Enter the value of Fahrenheit: ";
    cin >> f;

    float Celsius = convertCelsius(f);

    cout << Celsius;

    return 0;
}