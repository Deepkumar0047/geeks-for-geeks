/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> ans;
        
        if (root == NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while (!q.empty()) {
            
            int size = q.size();
            vector<int> level;
            
          
            for (int i = 0; i < size; i++) {
                
                Node* curr = q.front();
                q.pop();
                
                level.push_back(curr->data);
                
                if (curr->left)
                    q.push(curr->left);
                
                if (curr->right)
                    q.push(curr->right);
            }
            
         
            if (!leftToRight)
                reverse(level.begin(), level.end());
            
            
            for (int x : level)
                ans.push_back(x);
            
            leftToRight = !leftToRight;
        }
        
        return ans;
    }
};