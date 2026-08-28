class Solution {
public:
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            
            int low = 0;
            int high = m - 1;

            // Binary search in each row
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (mat[i][mid] == x)
                    return true;

                else if (mat[i][mid] < x)
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};