class Solution {
  public:
      void solve(int r,int c,vector<vector<int>>& maze,int n,vector<vector<int>>& vis,string path,vector<string>& ans){
          if(r == n-1 && c == n-1){
              ans.push_back(path);
              return;
          }
          int dr[]={1,0,0,-1};
          int dc[]={0,-1,1,0};
          char dir[]={'D','L','R','U'};
          
          for(int i=0;i<4;i++){
              int nr = r+dr[i];
              int nc = c+dc[i];
              
              if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                maze[nr][nc] == 1 &&
                vis[nr][nc] == 0) {
                    
                vis[nr][nc] = 1;
                solve(nr, nc, maze, n, vis,
                      path + dir[i], ans);
                vis[nr][nc] = 0;
            }
          }
      }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string>ans;
        
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
        return ans;
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        solve(0,0,maze,n,vis,"",ans);
        return ans;
        
    }
};