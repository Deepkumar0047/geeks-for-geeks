class Solution {
  public:
    double power(double b, int e) {

        long long exp = e;
        double ans = 1.0;

        if (exp < 0) {
            b = 1.0 / b;
            exp = -exp;
        }

        while (exp > 0) {

            if (exp % 2 == 1) {
                ans *= b;
            }

            b *= b;
            exp /= 2;
        }

        return ans;
    }
};