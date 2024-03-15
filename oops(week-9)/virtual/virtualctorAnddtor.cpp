// Can we make virtual constructor ? --> No (becoz when the ctor calls there is no Vtable in memory)
// Can we make virtual destructor ? --> Yes (To save leak memory and to calls derived class dtor)
#include <iostream>
using namespace std;

// parent class
class Base
{
public:
    // ctor -> Constructor
    Base()
    {
        cout << "Base class Ctor" << endl;
    }

    // dtor -> Destructor
    virtual ~Base()
    {
        cout << "Base class Dtor" << endl;
    }
};

// child class
class Derived : public Base
{

    int *a;

public:
    // ctor
    Derived()
    {
        a = new int[100];
        cout << "Derived class Ctor" << endl;
    }

    // dtor
    ~Derived()
    {
        delete[] a;
        // to delete this memory from heap we have to call dtor of derived to
        // save heap memory by Deleting the memory again (To call dtor of Derived we have to make virtual dtor of base class)
        cout << "Derived class Dtor" << endl;
    }
};

int main()
{
    Base *b = new Derived();
    delete b;

    return 0;
}