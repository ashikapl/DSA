// print all subarray using RE
#include <iostream>
#include <vector>
using namespace std;

void printSubarray_util(vector<int> &num, int start, int end)
{
    // base case
    if (end == num.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    printSubarray_util(num, start, end + 1);
}

void printSubarray(vector<int> &num)
{
    for (int start = 0; start < num.size(); start++)
    {
        int end = start;
        printSubarray_util(num, start, end);
    }
}

int main()
{
    vector<int> num{1, 2, 3, 4, 5};

    printSubarray(num);

    return 0;
}