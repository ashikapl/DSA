#include <iostream>
#include <vector>
#include <queue>
// #include <utility>

using namespace std;

class myComp {
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        int disA = a.first*a.first + a.second*a.second;
        int disB = b.first*b.first + b.second*b.second;
        return disA > disB; // This creates a min-heap based on distance
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;

    priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;

    for (auto& point : points) {
        pq.push({point[0], point[1]});
    }

    while (!pq.empty() && k--) {
        auto top = pq.top();
        ans.push_back({top.first, top.second});
        pq.pop();
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{1, 3}, { -2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    vector<vector<int>> result = kClosest(points, k);
    
    cout << "The " << k << " closest points to the origin are:" << endl;
    for (auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
