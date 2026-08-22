class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        // First k+1 elements
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }

        int index = 0;

        // Process remaining elements
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();

            minHeap.push(arr[i]);
        }

        // Empty the heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};