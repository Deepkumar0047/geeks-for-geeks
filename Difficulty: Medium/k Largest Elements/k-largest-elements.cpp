class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n = arr.size();
        
        priority_queue<int>maxHeap;
        for(int x : arr){
            maxHeap.push(x);
            
        }
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return ans;
        
    }
};