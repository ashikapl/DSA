// given k sorted array of size -> n we have to merge k sorted array in sorted form
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class info{
    public:
    int data; // element 
    int row; // array of 0th column becoz its 2D array
    int col; // index of each row 

    info(int val, int r, int c)
    {
        data = val;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(info* a, info* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKsortedArray(int arr[][5], int k, int n)
{
    priority_queue<info* , vector<info*>, compare> minHeap;

    // insert first element of every array 
    for(int i = 0; i < k; i++)
    {
        info*temp = new info(arr[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(!minHeap.empty())
    {
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);

        if(topCol + 1 < n)
        {
            info* newInfo = new info(arr[topRow][topCol+1],topRow,topCol+1);
            minHeap.push(newInfo);
        }
    }

    return ans;
}

int main()
{
    int arr[][5] = {{2,7,8,11,12},
                    {4,15,18,20,21},
                    {9,10,13,22,25},
                    {6,26,30,35,40}};

    int k = 4;
    int n = 5;

    vector<int> ans = mergeKsortedArray(arr,k,n);

    cout << "Printing the kSorted arrays:" << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }       

    return 0;         
}