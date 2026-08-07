/* Structure of Binary Tree Node
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

    void inorder(Node* root, vector<int> &ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};