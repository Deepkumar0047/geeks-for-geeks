class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(V, -1);
        queue<int> q;

        for (int i = 0; i < V; i++) {

            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < adj[node].size(); j++) {

                        int neighbour = adj[node][j];

                        if (color[neighbour] == -1) {
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        }
                        else if (color[neighbour] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};