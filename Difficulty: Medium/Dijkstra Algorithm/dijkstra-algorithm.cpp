class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Create adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   // Undirected graph
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto &it : adj[node]) {
                int neighbour = it.first;
                int weight = it.second;

                if (dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        return dist;
    }
};