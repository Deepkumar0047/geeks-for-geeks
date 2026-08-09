class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<pair<int, int>>> adj(V);

        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> isMST(V, 0);

        int cost = 0;

        pq.push({0, {0, -1}});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;

            pq.pop();

            if (isMST[node])
                continue;

            isMST[node] = 1;
            cost += wt;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (!isMST[adjNode]) {
                    pq.push({
                        edgeWeight,
                        {adjNode, node}
                    });
                }
            }
        }

        return cost;
    }
};