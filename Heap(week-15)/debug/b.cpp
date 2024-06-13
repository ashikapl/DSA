#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void firstKthElement(int arr[], int size, int k) {
    if (k > size) {
        cout << "k is larger than the size of the array." << endl;
        return;
    }

    // Max heap to keep track of the first k smallest elements
    priority_queue<int> maxHeap;

    for (int i = 0; i < size; i++) {
        if (maxHeap.size() < k) {
            maxHeap.push(arr[i]);
        } else if (arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    cout << "The " << k << "-th smallest element is " << maxHeap.top() << endl;
}

int main() {
    int arr[] = {3, 2, 4, 6, 4};
    int size = 5;
    int k = 3;

    firstKthElement(arr, size, k);

    return 0;
}
