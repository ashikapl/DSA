// Using friend keyword and function
#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A(int _val) : x(_val) {}

    // int getX() const
    // {
    //     return x;
    // }

    // void setX(int _val)
    // {
    //     x = _val;
    // }

    // Without using getter and setter
    friend class B;
    friend void print(const A &);
};

class B
{
public:
    void print(const A &a)
    {
        // cout << a.getX() << endl;
        cout << a.x << endl;
    }
};

// or we can use friend function also
void print(const A &a)
{
    cout << a.x << endl;
}

int main()
{
    A a(4);
    B b;
    b.print(a);
    print(a);

    return 0;
}