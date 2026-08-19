class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int src = 0; src < V; src++) {

            vector<int> dist(V, -1);
            vector<int> parent(V, -1);

            queue<int> q;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                for (int v : adj[u]) {

                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }

                    else if (parent[u] != v) {
                        int cycleLength = dist[u] + dist[v] + 1;
                        ans = min(ans, cycleLength);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};