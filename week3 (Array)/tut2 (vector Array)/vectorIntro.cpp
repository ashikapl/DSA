// how to check size, capacity, popback, pushback, remove, empty //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Create vector
    vector<int> arr{10, 20, 30};

    cout << arr.size() << endl;

    // add an element in vector //
    // insert
    arr.push_back(3);

    // how many elements are there in a function //
    cout << arr.size() << endl;

    // remove last element from the function //
    arr.pop_back();

    cout << arr.size() << endl;

    // strength how much it store in vector array //
    cout << arr.capacity() << endl;

    // true = 1 and false = 0 // check empty //
    cout << arr.empty() << endl;

    arr.clear();
    cout << arr.size() << endl;

    return 0;
}