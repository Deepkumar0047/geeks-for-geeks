class Solution {
public:
    bool detectCycle(int node, vector<int> adj[],vector<bool> &visited,vector<bool> &path)
    {
        visited[node] = true;
        path[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (detectCycle(neighbour, adj, visited, path))
                    return true;
            }
            else if (path[neighbour])
            {
                return true;
            }
        }

        path[node] = false;  
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
      
        vector<int> adj[V];

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        vector<bool> path(V, false);


        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detectCycle(i, adj, visited, path))
                    return true;
            }
        }

        return false;
    }
};