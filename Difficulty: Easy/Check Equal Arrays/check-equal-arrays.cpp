class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a==b;
    }
};