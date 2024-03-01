// class and objects
#include <iostream>
#include <string>
using namespace std;

class Animal
{
    // state / property ->eg
private:
    int weight;

public:
    int age;
    string type;

    // behavior / method or function -> eg
    void eat()
    {
        cout << "Eating" << endl;
    }

    void sleep()
    {
        cout << "Sleeping" << endl;
    }

    // this get and set function is used to acces the private date member
    int getWeight()
    {
        return weight;
    }

    void setWeight(int weight)
    {
        this->weight = weight; // here (this) is a pointer to the data member of class
        // it is used becoz of no colision in same name // for no confusion
    }
};

int main()
{
    // check size of empty class -> 1 always becoz class is present in the code
    // cout << "Size of class when empty: " << sizeof(Animal) << endl;

    // how to access -> access by making object of class -> eg
    // object creation

    // static
    Animal tom;

    // initialize value
    tom.age = 13;
    tom.type = "cat";

    // show output of the value
    cout << "In static --->" << endl;
    cout << "Age of tom:- " << tom.age << endl;
    cout << "Type of tom:- " << tom.type << endl;

    tom.eat();
    tom.sleep();

    // use to access private data member
    tom.setWeight(103);
    // print the weight
    cout << "Weight of tom: " << tom.getWeight() << endl;

    // dynamic
    Animal *jerry = new Animal;

    // inlialize
    cout << endl
         << "Dynamic --->" << endl;
    jerry->age = 12;
    jerry->sleep();
    jerry->type = "mouse";

    cout << "Jerry's age: " << jerry->age << endl;
    cout << "Jerry's type: " << jerry->type << endl;

    return 0;
}