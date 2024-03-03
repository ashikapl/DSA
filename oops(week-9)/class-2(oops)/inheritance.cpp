// About Inheritance
#include <iostream>
using namespace std;

// parent or super or base class
class cat
{
public:
    // data member
    int age;
    int weight;

    // data functionss
    void eat()
    {
        cout << "Cat and kitti both can eat" << endl;
    }
};

// child or derived or sub class
// syntax of calling parent or base class
class kitti : public cat // child class can access all the DM or DF of parent class
{
};

int main()
{
    // child class object
    kitti k;
    cout << k.age << endl; // some garbage value is printing becoz we don't inilialize it

    // call member function
    k.eat();

    // both the class parent and child having differet accessibility in private , protected and public
    // public can access both -> inside and outside of class
    // protected -> only inside class
    // private -> to access private data we have to use getter and setter

    return 0;
}