#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // classes that inherit this class
    // has to implement pure virtual function
};

class Sparrow : public Bird
{
private:
    void eat()
    {
        cout << "Sparrow is eating" << endl;
    }
    void fly()
    {
        cout << "Sparrow can fly" << endl;
    }
};

class Eagle : public Bird
{
private:
    void eat()
    {
        cout << "Eagle is eating" << endl;
    }
    void fly()
    {
        cout << "Eagle can fly" << endl;
    }
};

#endif
