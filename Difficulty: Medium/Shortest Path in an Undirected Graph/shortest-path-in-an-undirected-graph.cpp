class Solution {
public:
    vector<long long> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {

        vector<long long> dist(V + 1, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &it : adj[node]) {

                int v = it.first;
                int w = it.second;

                if(dist[node] + w < dist[v]) {

                    dist[v] = dist[node] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {

        vector<vector<pair<int,int>>> adj(V + 1);

        for(auto &e : edges){

            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        for(int i = 1; i <= V; i++)
            sort(adj[i].begin(), adj[i].end());

        vector<long long> dist1 = dijkstra(V, adj, src);
        vector<long long> dist2 = dijkstra(V, adj, dest);

        if(dist1[dest] == LLONG_MAX)
            return {-1};

        vector<int> ans;

        int curr = src;
        ans.push_back(curr);

        while(curr != dest){

            for(auto &it : adj[curr]){

                int nxt = it.first;
                int wt = it.second;

                if(dist1[curr] + wt + dist2[nxt] == dist1[dest]){

                    ans.push_back(nxt);
                    curr = nxt;
                    break;
                }
            }
        }

        return ans;
    }
};