class Solution {
  public:
    vector<int> extractPoints(vector<int>& arr) {
        vector<int> temp;

        // Remove consecutive duplicates
        for (int i = 0; i < arr.size(); i++) {
            if (temp.empty() || temp.back() != arr[i]) {
                temp.push_back(arr[i]);
            }
        }

        if (temp.size() <= 1)
            return temp;

        vector<int> ans;
        ans.push_back(temp[0]);

        // Find turning points
        for (int i = 1; i < temp.size() - 1; i++) {
            if ((temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) ||
                (temp[i] < temp[i - 1] && temp[i] < temp[i + 1])) {
                ans.push_back(temp[i]);
            }
        }

        ans.push_back(temp.back());

        return ans;
    }
};