class Solution {
  public:
  
  bool dfs(int node,vector<vector<int>>& adj,vector<int>& state){
      if(state[node]==1)
      return false;
      
      if(state[node]==2)
      return true;
      
      state[node]=1;
      
      for(int next : adj[node]){
          if(!dfs(next,adj,state))
          return false;
      }
      state[node]=2;
      return true;
  }
    bool canFinish(int n, vector<vector<int>>& pre){
        vector<vector<int>> adj(n);
        
        for(auto &p : pre){
            int u = p[0];
            int v = p[1];
            
            adj[v].push_back(u);
        }
        vector<int>state(n,0);
        
        for(int i=0;i<n;i++){
            if(state[i]==0){
                if(!dfs(i,adj,state))
                return false;
            }
        }
        return true;
    }
};