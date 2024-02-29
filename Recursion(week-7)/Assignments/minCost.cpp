// find the minimum cost tickets this solution time complexity is very baad without using DP
#include <iostream>
#include <vector>
using namespace std;

int minCostTickets(vector<int> &days, vector<int> &costs, int i)
{
    // base case
    if (i >= days.size())
    {
        return 0;
    }

    // solve one case
    int cost1 = costs[0] + minCostTickets(days, costs, i + 1);

    // 7 days cost tickets
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + minCostTickets(days, costs, j);

    // 30 days cost tickets
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + minCostTickets(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int main()
{
    vector<int> days{2, 6, 7, 8, 9, 10, 20};
    vector<int> costs{2, 7, 15};

    int cost = minCostTickets(days, costs, 0);

    cout << cost << endl;

    return 0;
}