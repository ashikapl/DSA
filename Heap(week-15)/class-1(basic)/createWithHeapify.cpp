// Build Heap with array
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

// create heap with array
void buildHeap(int arr[], int n)
{
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }
}

int main()
{
    int arr[] = {-1,12,56,43,6,78,87,5,44,3,23,32};
    int n = 11;

    buildHeap(arr,n);

    cout << "Printing the Heap:" << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}