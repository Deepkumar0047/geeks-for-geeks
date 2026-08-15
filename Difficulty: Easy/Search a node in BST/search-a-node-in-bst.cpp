/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        if(root == NULL)
        return false;
        
        if(root->data == key)
        return true;
        
        if(key < root->data)
        return search(root->left,key);
        
        return search(root->right,key);
        
    }
};