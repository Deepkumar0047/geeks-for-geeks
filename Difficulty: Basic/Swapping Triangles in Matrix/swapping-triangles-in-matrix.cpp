class Solution {
  public:
    void swapTriangle(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};