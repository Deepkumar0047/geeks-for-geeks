class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>> &prerequisites) {

        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);

        // Build graph
        for (auto &it : prerequisites) {
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (ans.size() == N)
            return ans;

        return {};
    }
};