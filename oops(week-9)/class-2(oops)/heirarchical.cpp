// Heirarchical Inheritance -> one parent class inherit by more than one child class
#include <iostream>
#include <string>
using namespace std;

// Parent class
class Car
{
public:
    string color;

    void speedUp()
    {
        cout << "Speeding Up " << endl;
    }
};

// child class
class Scorpio : public Car
{
};

// child class
class Fortuner : public Car
{
};

int main()
{
    //  in heirarchical inheritance more than one child class can access one parent class Data Members or Functions
    return 0;
}

// Fifth Inheritance -> called Hybrid -> mixer of all the types of inheritance (combination);
// In hybrid we can use any type of inheritance in combine form