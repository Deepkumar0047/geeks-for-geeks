class Solution {
public:
    bool DFS(int node, int parent, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (DFS(neighbour, node, adj, visited))
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges)
    {
        // Create adjacency list
        vector<int> adj[V];

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        // Handle disconnected components
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DFS(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};