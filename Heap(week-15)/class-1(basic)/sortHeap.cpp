// Sort Heap
#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    // ctor
    Heap()
    {
        size = 0;
    }
};

void heapify(int arr[], int n, int i)
{
    int index = i;
    int left = 2*i;
    int right = 2*i+1;
    int largest = index;

    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != index)
    {
        swap(arr[index],arr[largest]);
        index = largest;
        heapify(arr,n,index);
    }
}

void sortHeap(int arr[], int n)
{
    while(n != 1)
    {
        swap(arr[1],arr[n]);
        n--;

        heapify(arr,n,1);
        // yaha root pr jo value hai usko uski correct position pr pohchana hai, that's why we put 1 here
    }
}

int main()
{
    int arr[] = {-1,25,12,13,10,8,5};
    int n = 5;

    sortHeap(arr,n);

    cout << "Printing the Sorted Heap:" << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}