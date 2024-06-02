// Find uppercase and lowerCase of string
#include <iostream>
#include <cstring>
using namespace std;

void getUpperCase(char arr[])
{
    int n = strlen(arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z' && arr[i] != ' ')
        {
            arr[i] = arr[i] - 'a' + 'A';
        }
    }
}

void getLowerCase(char arr[])
{
    int n = strlen(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z' && arr[i] != ' ')
        {
            arr[i] = arr[i] - 'A' + 'a';
        }
    }
}

int main()
{
    char arr[10] = "ashika pl";

    getUpperCase(arr);

    cout << "Upper-Case:- " << arr << endl;

    getLowerCase(arr);

    cout << "Lower-Case:- " << arr;

    return 0;
}