/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
      void inorder(Node* root, vector<int>& arr) {
          if (root == NULL)
              return;

          inorder(root->left, arr);
          arr.push_back(root->data);
          inorder(root->right, arr);
      }

      vector<int> merge(Node* root1, Node* root2) {
          vector<int> a, b;

          // Inorder traversal of both BSTs
          inorder(root1, a);
          inorder(root2, b);

          vector<int> ans;

          int i = 0, j = 0;

          // Merge two sorted arrays
          while (i < a.size() && j < b.size()) {
              if (a[i] <= b[j]) {
                  ans.push_back(a[i]);
                  i++;
              }
              else {
                  ans.push_back(b[j]);
                  j++;
              }
          }

          // Remaining elements of a
          while (i < a.size()) {
              ans.push_back(a[i]);
              i++;
          }

          // Remaining elements of b
          while (j < b.size()) {
              ans.push_back(b[j]);
              j++;
          }

          return ans;
      }
  };