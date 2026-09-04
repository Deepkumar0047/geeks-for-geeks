class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();

        // Store {profit, deadline}
        vector<pair<int, int>> jobs;

        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Sort by decreasing profit
        sort(jobs.begin(), jobs.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // DSU parent array
        parent.resize(maxDeadline + 1);

        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int jobsDone = 0;
        int totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            // Find latest free slot <= deadline
            int slot = find(d);

            if (slot > 0) {
                jobsDone++;
                totalProfit += p;

                // Mark slot as occupied
                parent[slot] = find(slot - 1);
            }
        }

        return {jobsDone, totalProfit};
    }
};