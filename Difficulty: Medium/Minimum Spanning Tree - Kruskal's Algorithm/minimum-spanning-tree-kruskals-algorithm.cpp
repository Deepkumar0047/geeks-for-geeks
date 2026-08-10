class Solution {
public:
    vector<int> parent, rankk;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankk[a] < rankk[b])
            parent[a] = b;
        else if (rankk[a] > rankk[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rankk[a]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {

        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[2] < b[2];
             });

        parent.resize(V);
        rankk.assign(V, 0);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        int mstWeight = 0;
        int count = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (find(u) != find(v)) {
                mstWeight += w;
                unite(u, v);
                count++;

                if (count == V - 1)
                    break;
            }
        }

        return mstWeight;
    }
};