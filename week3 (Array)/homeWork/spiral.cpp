// Spiral Print in martix //
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> v)
{
    vector<int> ans;
    int m = v.size();
    int n = v[0].size();
    int total_element = m * n;

    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = m - 1;
    int startingCol = 0;

    int count = 0;
    while (count < total_element)
    {
        // Print starting-Row
        for (int i = startingCol; i < endingCol && count < total_element; i++)
        {
            ans.push_back(v[startingRow][i]);
            count++;
        }
        startingRow++;

        // Print ending-column
        for (int i = startingRow; i < endingRow && count < total_element; i++)
        {
            ans.push_back(v[i][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending-Row
        for (int i = startingCol; i < endingCol && count < total_element; i++)
        {
            ans.push_back(v[endingRow][i]);
            count++;
        }
        endingRow--;

        // Print starting-Column
        for (int i = startingRow; i < endingRow && count < total_element; i++)
        {
            ans.push_back(v[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return ans;
}

int main()
{
    vector<vector<int>> v{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    spiralPrint(v);

    return 0;
}