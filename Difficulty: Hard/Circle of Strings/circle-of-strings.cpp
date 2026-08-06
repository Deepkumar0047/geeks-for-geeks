class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis) {
        vis[node] = true;

        for (int next : adj[node]) {
            if (!vis[next])
                dfs(next, adj, vis);
        }
    }

    bool isCircle(vector<string> &arr) {
        vector<int> adj[26], revAdj[26];
        vector<int> indegree(26, 0), outdegree(26, 0);

        // Build graph
        for (string &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';

            adj[u].push_back(v);
            revAdj[v].push_back(u);

            outdegree[u]++;
            indegree[v]++;
        }

        // Check indegree == outdegree
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != outdegree[i])
                return false;
        }

        // Find a starting vertex
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (outdegree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1)
            return true;

        // DFS on original graph
        vector<bool> vis(26, false);
        dfs(start, adj, vis);

        for (int i = 0; i < 26; i++) {
            if (outdegree[i] > 0 && !vis[i])
                return false;
        }

        // DFS on reversed graph
        fill(vis.begin(), vis.end(), false);
        dfs(start, revAdj, vis);

        for (int i = 0; i < 26; i++) {
            if (outdegree[i] > 0 && !vis[i])
                return false;
        }

        return true;
    }
};