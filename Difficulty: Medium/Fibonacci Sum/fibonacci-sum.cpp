class Solution {
  public:
    int fibSum(int n) {
        const int MOD = 1000000007;

        if (n == 0) return 0;
        if (n == 1) return 1;

        long long a = 0, b = 1;

        for (int i = 2; i <= n + 2; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }

        return (b - 1 + MOD) % MOD;
    }
};