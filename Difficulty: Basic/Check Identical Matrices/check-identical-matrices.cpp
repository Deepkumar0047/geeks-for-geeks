class Solution {
public:
    bool identicalMat(vector<vector<int>> &Grid1, 
                      vector<vector<int>> &Grid2) {
        
        int n = Grid1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Grid1[i][j] != Grid2[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};