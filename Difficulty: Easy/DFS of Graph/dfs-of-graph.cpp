class Solution {
public:

    void dfsTraversal(int node, vector<vector<int>>& adj,
                      vector<bool>& visited, vector<int>& ans) {

        visited[node] = true;
        ans.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfsTraversal(neighbour, adj, visited, ans);
            }
        }
    }
        vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();

        vector<bool> visited(V, false);
        vector<int> ans;

        dfsTraversal(0, adj, visited, ans);

        return ans;
    }
};
        
