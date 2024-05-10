// Valid BST from Preorder 
#include<iostream>
#include<climits>
using namespace std;

void buildCheck(int &i, int min, int max, int arr[], int n)
{
    if(i == n) return;

    if(arr[i] > min && arr[i] < max)
    {
        int data = arr[i++];
        buildCheck(i,min,data,arr,n);
        buildCheck(i,data,max,arr,n);
    }
}

int validBSTfromPreorder(int arr[], int n)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    buildCheck(i,min,max,arr,n);

    return (i == n) ? 1 : 0;
}

int main()
{
    int arr[] = {10, 5, 1, 7, 40, 50};
    int n = 6;

    int ans = validBSTfromPreorder(arr,n);
    if(ans == 1)
    {
        cout << "BST is valid from this preorder array!" << endl;
    }
    else
    {
        cout << "BST is not valid!" << endl;
    }

    return 0;
} 