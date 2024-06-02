// palindrome means the word is read ans seen same from both side left to right or right to left
#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;

    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;
}

int main()
{
    char word[10] = "kadak";

    cout << "The word is Palindrome or not check:-> " << checkPalindrome(word);

    return 0;
}