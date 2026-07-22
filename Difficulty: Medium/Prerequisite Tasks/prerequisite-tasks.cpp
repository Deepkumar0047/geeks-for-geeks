class Solution {
public:
    bool isPossible(int N, vector<pair<int, int>>& pre) {

        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);

        // Build graph
        for (auto &it : pre) {
            int u = it.second;
            int v = it.first;

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return count == N;
    }
};