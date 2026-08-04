class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {

        if (knightPos == targetPos)
            return 0;

        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

        vector<pair<int, int>> dir = {
            {-2, -1}, {-2, 1},
            {-1, -2}, {-1, 2},
            {1, -2}, {1, 2},
            {2, -1}, {2, 1}
        };

        queue<pair<pair<int, int>, int>> q;

        q.push({{knightPos[0], knightPos[1]}, 0});
        vis[knightPos[0]][knightPos[1]] = true;

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int steps = curr.second;

            for (auto &d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny]) {

                    if (nx == targetPos[0] && ny == targetPos[1])
                        return steps + 1;

                    vis[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
    }
};