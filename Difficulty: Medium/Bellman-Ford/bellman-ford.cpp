class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 100000000);
        dist[src] = 0;

        int e = edges.size();

       
        for (int i = 0; i < V - 1; i++) {
            bool flag = false;

            for (int j = 0; j < e; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] == 100000000)
                    continue;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    flag = true;
                }
            }

        
            if (!flag)
                break;
        }

  
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == 100000000)
                continue;

            if (dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};