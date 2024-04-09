// Deque using stl
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_front(2);
    d.push_front(4);
    d.push_front(10);
    d.push_back(50);

    cout << "Size: " << d.size() << endl;

    d.pop_front();

    cout << "Size: " << d.size() << endl;

    d.pop_back();

    cout << "Size: " << d.size() << endl;

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    return 0;
}