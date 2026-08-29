class Solution {
public:
    vector<vector<int>> sortedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> arr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(mat[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = arr[k++];
            }
        }

        return mat;
    }
};