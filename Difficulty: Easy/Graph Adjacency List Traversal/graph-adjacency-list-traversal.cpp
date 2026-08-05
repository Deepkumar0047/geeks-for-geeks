class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {

        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        return adj;
    }
};