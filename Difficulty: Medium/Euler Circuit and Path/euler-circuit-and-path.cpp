class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int isEulerCircuit(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);

        int start = -1;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0) {
                start = i;
                break;
            }
        }

        if (start == -1)
            return 2;

        dfs(start, adj, vis);

        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0 && !vis[i])
                return 0;
        }

        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                odd++;
        }

        if (odd == 0)
            return 2;
        else if (odd == 2)
            return 1;
        else
            return 0;
    }
};