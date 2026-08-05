class Solution {
  public:
    vector<vector<int>> adjToMat(vector<vector<int>>& adj) {
        int V=adj.size();
        
        vector<vector<int>>matrix(V,vector<int>(V,0));
        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                matrix[i][j]=1;
            }
        }
        return matrix;
    }
};