// Prata Spoj problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> cooksRanks, int nP, int mid)
{
    int currPrata = 0; // current prata count start from 0;
    for (int i = 0; i < cooksRanks.size(); i++)
    {
        int R = cooksRanks[i];
        int j = 1; // to count R means = 1R + 2R + 3R.... so on.
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + j * R <= mid)
            {
                ++currPrata;
                timeTaken += j * R;
                ++j;
            }
            else
            {
                break;
            }
        }
        if (currPrata >= nP)
        {
            return true;
        }
    }
    return false;
}

int miniTimeToCompleteOrder(vector<int> cooksRanks, int nP)
{
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end()); // max element
    int end = highestRank * (nP * (nP + 1) / 2);                          // formula of highest value or rank
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(cooksRanks, nP, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int T;
    cout << "Enter the no. of test cases:- ";
    cin >> T;

    while (T--)
    {
        int nP; // here np is no. of prata
        int nC; // here nC is no. of cooks
        cin >> nP >> nC;

        vector<int> cooksRanks;
        while (nC--)
        {
            int R;
            cin >> R;
            cooksRanks.push_back(R);
        }

        cout << "Minimum time to make all the parta's:--> " << miniTimeToCompleteOrder(cooksRanks, nP);
    }

    return 0;
}