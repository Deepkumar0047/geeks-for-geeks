class Solution {
    struct Node{
        Node* links[26];
        
        Node(){
            for(int i = 0;i < 26;i++){
                links[i] = nullptr;
            }
        }
    };
  public:
    int countSubs(string& s) {
        Node* root = new Node();
        int count = 0;
        int n = s.size();
        
        for(int i = 0;i < n;i++){
            Node* curr = root;
            
            for(int j = i;j<n;j++){
                int idx = s[j] - 'a';
                
                if(curr->links[idx] == nullptr){
                    curr->links[idx] = new Node();
                    count++;
                }
                curr = curr->links[idx];
            }
        }
        return count;
    }
};