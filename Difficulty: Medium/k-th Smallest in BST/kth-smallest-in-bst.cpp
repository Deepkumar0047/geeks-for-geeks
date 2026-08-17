/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int count = 0;
    int ans = -1;

    void inorder(Node* root, int k) {
        if (root == NULL)
            return;

        // Left subtree
        inorder(root->left, k);

        // Visit current node
        count++;

        if (count == k) {
            ans = root->data;
            return;
        }

        // Right subtree
        inorder(root->right, k);
    }

    int kthSmallest(Node* root, int k) {
        inorder(root, k);
        return ans;
    }
};