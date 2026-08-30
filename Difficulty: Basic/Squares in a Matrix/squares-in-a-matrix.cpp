class Solution {
public:
    long long squaresInMatrix(int m, int n) {
        long long ans = 0;

        int k = min(m, n);

        for (int i = 1; i <= k; i++) {
            ans += 1LL * (m - i + 1) * (n - i + 1);
        }

        return ans;
    }
};