class Solution {
  public:
  
  void DFS(int node,vector<vector<int>>& adj,vector<bool>& visited,int c,int d){
      visited[node]=true;
      
      for(int next : adj[node]){
          if((node == c && next == d)||(node == d && next == c))
          continue;
          
          
          if(!visited[next]){
              DFS(next,adj,visited,c,d);
          }
      }
  }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>>adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<bool>visited(V,false);
        DFS(c,adj,visited,c,d);
        return !visited[d];
        
    }
};