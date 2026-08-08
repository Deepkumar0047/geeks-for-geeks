class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int totalSum = 0;

        int currMax = 0;
        int maxSum = arr[0];

        int currMin = 0;
        int minSum = arr[0];

        for (int x : arr) {
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            totalSum += x;
        }
        if (maxSum < 0)
            return maxSum;
        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};