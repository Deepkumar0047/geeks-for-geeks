class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : arr) {
            pq.push(num);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};