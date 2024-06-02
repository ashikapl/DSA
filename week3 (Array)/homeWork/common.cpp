// Find the common element from 3 sorted arrays //
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> commonElement(int A[], int B[], int C[], int sizeA, int sizeB, int sizeC)
{
    vector<int> ans;
    set<int> st;
    int i, j, k;
    i = j = k = 0;
    while (i < sizeA && j < sizeB && k < sizeC)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            st.insert(A[i]);
            i++, j++, k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    int A[] = {20, 30, 40, 50, 80};
    int sizeA = 5;
    int B[] = {10, 40, 60, 80, 100, 120};
    int sizeB = 6;
    int C[] = {5, 15, 40, 70, 75, 80, 130};
    int sizeC = 7;

    vector<int> ans = commonElement(A, B, C, sizeA, sizeB, sizeC);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}