#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate, count = 0;
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
    }
    if (count > nums.size() / 2)
    {
        return candidate;
    }
    else
    {
        return -1; // or any other value that indicates no majority element exists
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 2, 2, 4, 2};
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}