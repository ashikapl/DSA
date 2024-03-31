#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum_helper(vector<int> &A, int B, vector<int> &v, vector<vector<int>> &ans, int index)
{
    if (B == 0)
    {
        ans.push_back(v);
        return;
    }
    if (B < 0)
    {
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        if (i != index && A[i] == A[i - 1])
            continue; // Skip duplicates
        v.push_back(A[i]);
        combinationSum_helper(A, B - A[i], v, ans, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> v;
    sort(A.begin(), A.end());
    combinationSum_helper(A, B, v, ans, 0);
    return ans;
}

int main()
{
    vector<int> A = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(A, target);

    cout << "Combinations of elements in A that sum up to " << target << " are:" << endl;
    for (auto &combination : result)
    {
        cout << "[";
        for (int i = 0; i < combination.size(); i++)
        {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
