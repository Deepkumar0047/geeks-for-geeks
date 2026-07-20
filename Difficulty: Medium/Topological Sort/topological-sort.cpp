class Solution {
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                DFS(neighbour, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges)
    {
        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        stack<int> st;

        // Perform DFS for every component
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, visited, st);
            }
        }

        vector<int> ans;

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};