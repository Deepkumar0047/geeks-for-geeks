class Solution {
public:

    bool DFS(vector<vector<int>>& adj, int node,
            vector<bool>& visited, int count, int N) {

        visited[node] = true;
        count++;

        if (count == N)
            return true;

        for (int j = 0; j < adj[node].size(); j++) {
            int next = adj[node][j];
            if (!visited[next]) {
                if (DFS(adj, next, visited, count, N))
                    return true;
            }
        }
        visited[node] = false;
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (DFS(adj, i, visited, 0, n))
            return true;
        }

        return false;
    }
};