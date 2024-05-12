// Insert the elements in heap  and create heap by inserting elements and deletion
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

    void insert(int val)
    {
        // insert value
        size = size + 1;
        int index = size;
        arr[index] = val;

        // place the value at its correct position
        while(index > 1)
        {
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex])
            {
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int removeRoot()
    {
        int ans = arr[1];

        // replace root node value to last node value
        arr[1] = arr[size];
        size--;

        // place it on correct position
        int index = 1;

        while(index < size)
        {
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;
          
            if(left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if(right <= size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if(largest == index)
            {
                break;
            }
            else
            {
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }

        return ans;
    }
};

void heapify(int arr[], int n, int i)
{
    int index = i;
    int left = 2*i;
    int right = 2*i+1;
    int largest = index;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
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

int main()
{
    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;

    // cout << "Printing the Heap" << endl;
    // for(int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }
    // cout << endl;

    // h.insert(120);

    // cout << endl;
    // cout << "Printing the Heap after insertion" << endl;
    // for(int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }
    // cout << endl;

    // creation by inserting the values

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80); 
    h.insert(100);
    // h.size = 6;

    cout << "Printing the Heap" << endl;
    for(int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.removeRoot();

    cout << "Printing the Heap" << endl;
    for(int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}