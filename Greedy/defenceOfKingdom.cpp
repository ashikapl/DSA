// Defence of a Kingdom
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Example for this code
// x,y,n = 15, 8, 3
// a, b = 3, 8
// a, b = 11, 2
// a, b = 8, 6
// answer is -> (12) is the largest Grid where no kingdom cover the area

int main()
{
    int x, y, n;
    cout << "Enter x,y,n: ";
    cin >> x >> y >> n;
    int t = n;

    vector<int> rowCo; //rowCoordinate
    vector<int> colCo; //colCoordinate

    rowCo.push_back(0);
    colCo.push_back(0);

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        rowCo.push_back(a);
        colCo.push_back(b);
    }

    rowCo.push_back(x+1);
    colCo.push_back(y+1);

    sort(rowCo.begin(), rowCo.end());
    sort(colCo.begin(), colCo.end());

    // For row length
    int maxLen = INT_MIN;
    for(int i = 1; i < rowCo.size(); i++)
    {
        int a = rowCo[i-1];
        int b = rowCo[i];

        maxLen = max(maxLen, b-a-1);
    }

    // For column length
    int maxWidth = INT_MIN;
    for(int i = 1; i < colCo.size(); i++)
    {
        int a = colCo[i-1];
        int b = colCo[i];

        maxWidth = max(maxWidth, b-a-1);
    }

    cout << "Largest Grid is: " << (maxLen * maxWidth) << endl;

    return 0;
}