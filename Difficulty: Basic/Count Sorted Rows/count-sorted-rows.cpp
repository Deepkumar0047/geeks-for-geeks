class Solution {
public:
    int sortedCount(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            bool increasing = true;
            bool decreasing = true;

            for (int j = 1; j < m; j++) {
                if (mat[i][j] <= mat[i][j - 1])
                    increasing = false;

                if (mat[i][j] >= mat[i][j - 1])
                    decreasing = false;
            }

            if (increasing || decreasing)
                count++;
        }

        return count;
    }
};