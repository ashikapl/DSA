#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void permute(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    if (start == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;
    for (int i = start; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            continue;
        }
        visited[nums[i]] = true;
        swap(nums[i], nums[start]);
        permute(nums, ans, start + 1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permute(nums, ans, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = permuteUnique(nums);

    cout << "Unique Permutations:" << endl;
    for (auto &permutation : result)
    {
        cout << "[";
        for (int i = 0; i < permutation.size(); i++)
        {
            cout << permutation[i];
            if (i < permutation.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
