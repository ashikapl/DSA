// Multi-Level Inheritance -> one parent class and more than one child class
#include <iostream>
#include <string>
using namespace std;

// parent class
class Fruit
{
public:
    int weight;

    // constructor -> initializing the value
    Fruit()
    {
        weight = 12;
    }
};

// child class
class Mango : public Fruit
{
public:
    string name;

    // constructor -> initializing the value
    Mango()
    {
        name = "Aam";
    }
};

// Grand child class
class Alphanso : public Mango
{
public:
    string type;

    // constructor -> initializing the value
    Alphanso()
    {
        type = "Ek prakar ka aam";
    }
};

int main()
{
    // grand child class object
    Alphanso obj;
    cout << obj.weight << endl
         << obj.name << endl
         << obj.type << endl;

    return 0;
}