/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        
        if (root == NULL)
            return ans;
        
        stack<Node*> st;
        st.push(root);
        
        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            
            ans.push_back(curr->data);
            
            // Push right child first
            if (curr->right)
                st.push(curr->right);
            
            // Push left child second
            if (curr->left)
                st.push(curr->left);
        }
        
        return ans;
    }
};