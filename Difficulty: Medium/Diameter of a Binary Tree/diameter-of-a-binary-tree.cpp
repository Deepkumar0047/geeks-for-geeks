/*Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    int ans = 0;

    int height(Node* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Diameter passing through current node
        ans = max(ans, left + right);

        // Return height
        return 1 + max(left, right);
    }

    int diameter(Node* root) {
        ans = 0;
        height(root);
        return ans;
    }
};