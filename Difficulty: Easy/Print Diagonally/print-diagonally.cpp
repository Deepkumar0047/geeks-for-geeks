class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> ans;

        // Start from first row
        for (int col = 0; col < n; col++) {
            int i = 0;
            int j = col;

            while (i < n && j >= 0) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        // Start from last column
        for (int row = 1; row < n; row++) {
            int i = row;
            int j = n - 1;

            while (i < n && j >= 0) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return ans;
    }
};