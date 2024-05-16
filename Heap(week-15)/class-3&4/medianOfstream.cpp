// Median of a stream
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int signum(int a, int b)
{
    if(a == b)
    {
        return 0;
    }
    else if(a > b)
    {
        return 1;
    }
    else  // (a < b)
    {
        return -1;
    }
}

void medainOfStream(int &median, priority_queue<int, vector<int>, greater<int>> &minHeap,priority_queue<int> &maxHeap,int element)
{
    switch(signum(minHeap.size(),maxHeap.size()))
    {
        case 0:
                if(element > median) // median ki val choti hoto push in minHeap
                {
                    minHeap.push(element);
                    median = minHeap.top();
                }
                else // badi hoto push in maxHeap
                {
                    maxHeap.push(element);
                    median = maxHeap.top();
                }
                break;
        case 1:
                if(element > median)
                {
                    int minTop = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(minTop);
                    minHeap.push(element);
                    median = (minHeap.top()+maxHeap.top())/2;
                }
                else
                {
                    maxHeap.push(element);
                    median = (minHeap.top()+maxHeap.top())/2;
                }
                break;
        case -1:
                // minHeap.size() < maxHeap.size()
                if(element > median)
                {
                    minHeap.push(element);
                    median = (minHeap.top()+maxHeap.top())/2;
                }
                else
                {
                    int maxTop = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(maxTop);
                    maxHeap.push(element);
                    median = (minHeap.top()+maxHeap.top())/2;
                }
                break;
    }

    // if(minHeap.size() == maxHeap.size())
    // {
    //     if(element > median) // median ki val choti hoto push in minHeap
    //     {
    //         minHeap.push(element);
    //         median = minHeap.top();
    //     }
    //     else // badi hoto push in maxHeap
    //     {
    //         maxHeap.push(element);
    //         median = maxHeap.top();
    //     }

    // }
    // else if(minHeap.size() > maxHeap.size())
    // {
    //     if(element > median)
    //     {
    //         int minTop = minHeap.top();
    //         minHeap.pop();
    //         maxHeap.push(minTop);
    //         minHeap.push(element);
    //         median = (minHeap.top()+maxHeap.top())/2;
    //     }
    //     else
    //     {
    //         maxHeap.push(element);
    //         median = (minHeap.top()+maxHeap.top())/2;
    //     }

    // }
    // else{
    //     // minHeap.size() < maxHeap.size()
    //     if(element > median)
    //     {
    //         minHeap.push(element);
    //         median = (minHeap.top()+maxHeap.top())/2;
    //     }
    //     else
    //     {
    //         int maxTop = maxHeap.top();
    //         maxHeap.pop();
    //         minHeap.push(maxTop);
    //         maxHeap.push(element);
    //         median = (minHeap.top()+maxHeap.top())/2;
    //     }
    // }
}

int main()
{
    int arr[] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for(int i = 0; i < n; i++)
    {
        int element = arr[i];
        medainOfStream(median,minHeap,maxHeap,element);
        cout << "->" << median << endl;
    }

    return 0;
}