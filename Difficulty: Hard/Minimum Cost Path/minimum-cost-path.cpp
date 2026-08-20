class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto current = pq.top();
            pq.pop();

            int cost = current.first;
            int r = current.second.first;
            int c = current.second.second;

            if (cost > dist[r][c])
                continue;

            if (r == n - 1 && c == n - 1)
                return cost;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n) {

                    int newCost = cost + grid[nr][nc];

                    if (newCost < dist[nr][nc]) {

                        dist[nr][nc] = newCost;

                        pq.push({
                            newCost,
                            {nr, nc}
                        });
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};