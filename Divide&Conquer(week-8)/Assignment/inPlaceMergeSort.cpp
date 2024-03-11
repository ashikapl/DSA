// In-Place Merge Sort
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
    int totalLength = end - start + 1;
    int gap = totalLength / 2 + totalLength % 2; // make ceil

    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            ++i, ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, mid, end);
}

vector<int>
sortArray(vector<int> &v)
{
    mergeSort(v, 0, v.size() - 1);
    return v;
}

int main()
{
    vector<int> v{5, 2, 1, 3};

    sortArray(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}