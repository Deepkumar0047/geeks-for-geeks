class Solution {
public:
    bool sumOfRowCol(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int k = min(n, m);

        for (int i = 0; i < k; i++) {
            int rowSum = 0;
            int colSum = 0;

            for (int j = 0; j < m; j++) {
                rowSum += mat[i][j];
            }

            for (int j = 0; j < n; j++) {
                colSum += mat[j][i];
            }

            if (rowSum != colSum) {
                return false;
            }
        }

        return true;
    }
};