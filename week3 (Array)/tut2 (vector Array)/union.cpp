// Union of two array //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sizeA = 5;

    int brr[] = {6, 7, 8, 9};
    int sizeB = 4;

    vector<int> ans;

    // Puting the value of arr in ans ..
    for (int i = 0; i < sizeA; i++)
    {
        ans.push_back(arr[i]);
    }

    // Puting the value of brr in ans ..
    for (int i = 0; i < sizeB; i++)
    {

        ans.push_back(brr[i]);
    }

    // print
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}