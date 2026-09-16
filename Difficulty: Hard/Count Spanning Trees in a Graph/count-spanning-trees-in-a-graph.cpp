class Solution {
  public:
    
    int det(vector<vector<int>> a) {
        int n = a.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int p = i;

            while (p < n && a[p][i] == 0)
                p++;

            if (p == n)
                return 0;

            if (p != i) {
                swap(a[p], a[i]);
                ans = -ans;
            }

            for (int j = i + 1; j < n; j++) {
                while (a[j][i] != 0) {
                    int q = a[i][i] / a[j][i];

                    for (int k = i; k < n; k++)
                        a[i][k] -= q * a[j][k];

                    swap(a[i], a[j]);
                    ans = -ans;
                }
            }

            ans *= a[i][i];
        }

        return abs(ans);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return 1;

        vector<vector<int>> lap(n, vector<int>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        vector<vector<int>> mat(n - 1, vector<int>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                mat[i][j] = lap[i][j];
            }
        }

        return det(mat);
    }
};