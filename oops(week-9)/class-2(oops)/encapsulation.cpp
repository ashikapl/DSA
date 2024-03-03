// Encapsulation topic
#include <iostream>
#include <string>
using namespace std;

// when all the data members are private it means -> full or perfect encapsulation concept
// here class is like -> data hiding or protected the data in separate class -> Is Encapsulation concept
class human
{
private:
    // Data members
    int age;
    int weight;
    string name;

public:
    // Data functionss
    void eat()
    {
        cout << "Human can eat" << endl;
    }

    // using getter and setter to access private data member
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{
    return 0;
}