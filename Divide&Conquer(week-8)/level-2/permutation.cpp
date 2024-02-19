// BackTracking question -> a special form of recursion where all the possible solution are done without
// repeat any solution again

// Permutation of string -> permutation means har ek character har ek position pr aana chahta hai
#include <iostream>
#include <string>
using namespace std;

void permutation(string &str, int i) // when we use pass by reference in parameters to avoid repeation in
// solution we have to use backTracking in recursive function
{
    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }

    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);

        // Recursive call
        permutation(str, i + 1);

        // BackTracking -> recreate original string or arr
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";

    int i = 0;

    permutation(str, i);

    return 0;
}