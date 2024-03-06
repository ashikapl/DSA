// Run-Time polymorphism
#include <iostream>
using namespace std;

class Animal
{
public:
    // // constructor
    Animal()
    {
        cout << "I am Animal Constructor" << endl;
    }

    virtual void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    // constructor
    Dog()
    {
        cout << "I am Dog Constructor" << endl;
    }

    // over-riding
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    // Dog a;
    // a.speak();

    // Dynamic
    // Animal *a = new Animal();
    // a->speak();

    // Dog *b = new Dog();
    // b->speak();

    // pointer function is calling without adding virtual keyword in parent class
    // DownCasting
    // Animal *a = new Dog();
    // a->speak();

    // UpCasting
    // Dog *b = (Dog *)new Animal();
    // b->speak();

    // constructor call
    Animal *a = new Animal(); // only Animal (parent class) constructor calls

    Dog *b = new Dog(); // firstly Parent class constructor calls than child class constructor call

    return 0;
}