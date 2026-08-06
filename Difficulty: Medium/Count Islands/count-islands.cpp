class Solution {
  public:
  
  void dfs(vector<vector<char>>& grid,int i ,int j,int n,int m)
  {
      if(i<0 || j<0 || i>=n ||j>=m || grid[i][j]=='W')
      return;
      
      grid[i][j]='W';
      
      int dx[]={-1,-1,-1,0,0,1,1,1};
      int dy[]={-1,0,1,-1,1,-1,0,1};
      
      for(int k=0;k<8;k++){
          dfs(grid,i+dx[k],j+dy[k],n,m);
      }
  }
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
        
    }
};