// Replace spaces of array
#include <iostream>
#include <cstring>
using namespace std;

void replaceSpaces(char sentence[])
{
    int n = strlen(sentence);

    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '@';
        }
    }
}

int main()
{
    char sentence[20];
    cin.getline(sentence, 20);

    cout << "Initial sentence is:- " << sentence << endl;

    replaceSpaces(sentence);

    cout << "After replace:--> " << sentence << endl;

    return 0;
}