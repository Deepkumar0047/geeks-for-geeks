class Solution {
  public:
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        vector<int>ans;
        
        if(n==1){
            for(int j=0;j<m;j++){
                ans.push_back(mat[0][j]);
            }
            return ans;
        }
        if(m==1){
            for(int i=0;i<n;i++){
                ans.push_back(mat[i][0]);
            }
            return ans;
        }
          for (int j = 0; j < m; j++) {
            ans.push_back(mat[0][j]);
        }

        for (int i = 1; i < n; i++) {
            ans.push_back(mat[i][m - 1]);
        }

        for (int j = m - 2; j >= 0; j--) {
            ans.push_back(mat[n - 1][j]);
        }

        for (int i = n - 2; i >= 1; i--) {
            ans.push_back(mat[i][0]);
        }

        return ans;
    }
};
