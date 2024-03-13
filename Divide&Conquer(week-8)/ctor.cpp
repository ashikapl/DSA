// Can constructor be private in class ?
// -> Yess
#include <iostream>
using namespace std;

class Box
{
private:
    int width;
    Box(int _w) : width(_w) {}

public:
    int getWidth()
    {
        return width;
    }

    void SetWidth(int _w)
    {
        width = _w;
    }

    friend class BoxFactory;
};

class BoxFactory
{
private:
    int count; // here count is used for counting the number of box's

public:
    Box getBox(int _w)
    {
        ++count;
        return Box(_w);
    }
};

int main()
{
    BoxFactory bfact;
    Box b = bfact.getBox(5);

    cout << b.getWidth() << endl;

    return 0;
}