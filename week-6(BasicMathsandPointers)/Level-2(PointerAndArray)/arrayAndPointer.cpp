#include <iostream>
using namespace std;

void checkArraySize(int arr[]) // here size of array is 8 becoz it pass pointer of array(pass by reference)
{
    cout << "Size of array in another function:- " << sizeof(arr) << endl;

    arr[0] = 50;
}

void update(int *p) // here is a new pointer which store same address as main funtion pointer but its own address is different
{
    cout << "Address stored inside p is: " << p << endl;
    cout << "Address of p  is:" << &p << endl;
    *p = *p + 10;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    // cout << arr << endl; // here arr, &arr, &arr[0]  this all are store base address of array
    // cout << arr[0] << endl;
    // cout << &arr << endl;
    // cout << &arr[0] << endl;
    // cout << *arr << endl; // arr[0] and *arr both show first element becoz arr store base address of array and  *arr locate the value store in this address
    // cout << endl;

    // // create a pointer of array
    // int *p = arr;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << endl;
    // cout << *p << endl;
    // cout << *arr << endl; // arr also store base address of array

    // int i = 0;
    // cout << arr[i] << endl; // arr[i] and i[arr] are same
    // cout << i[arr] << endl;
    // cout << arr[i + 1] << endl; // arr[i+1] and i[arr +1] are same
    // cout << i[arr + 1] << endl;

    // arr = arr + 1; // this statement is wrong we can't change the value store in symbol table

    // int *ptr = arr;
    // ptr = ptr + 1;
    // cout << *ptr << endl; // but we can change address store in pointer of an array

    // print size of array in main funtion
    cout << "size of array in main function:- " << sizeof(arr) << endl;
    // here size of array is 5*4 = 20; 4 is for int size

    // print array
    cout << "Before updation:- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    checkArraySize(arr);

    // print array
    cout << "After updation:- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int a = 5;
    cout << "Address of a is: " << &a << endl;
    int *ptr = &a;
    cout << "address stored in ptr is: " << ptr << endl;
    cout << "Address of ptr is: " << &ptr << endl;
    update(ptr);
    cout << "value of a is: " << a << endl;

    return 0;
}