#include<iostream>
#include<queue>
using namespace std;

void streamMedian(int A[], int n) {
    priority_queue<int> g, s;
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();
        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() == s.size())
            cout << (double)s.top() << endl;
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0)/ 2) << endl;
    }
}

int main()
{
    int A[] = {2,3,4,5,6,7,6};
    int n = 7;
    streamMedian(A,n);

    return 0;
}