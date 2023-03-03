///// ####### 1. 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minimizeCost(vector<int> arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
    }

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        int sum = x + y;
        totalCost += sum;
        minHeap.push(sum);
    }

    return totalCost;
}

//int main() {
//    vector<int> arr = { 25, 100, 20 };
//    cout << minimizeCost(arr) << endl;
//    return 0;
//}