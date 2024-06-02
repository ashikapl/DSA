#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n)
{
    // str is character array and n is the length of the character array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (str[i] == str[j])
                break;
        if (i == j)
            str[index++] = str[i];
    }

    return str;
}

int main()
{
    char str[] = "noon";
    int n = strlen(str);

    removeDuplicate(str, n);

    cout << str;
}