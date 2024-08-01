// find the min amount of money to buy all the candies with an offer (k candy free)
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int candies[] = {2,8,6,9,4,7};
    int n = 6;
    int k = 2;

    sort(candies, candies+n);

    int amount = 0;
    int buy = 0;
    int free = n-1;

    while(buy <= free)
    {
        amount += candies[buy];
        buy++;
        free -= k;
    }

    cout << "Min amount is:- " << amount << endl;

    return 0;
}