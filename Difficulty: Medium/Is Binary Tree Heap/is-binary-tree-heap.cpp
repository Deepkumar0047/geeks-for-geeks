/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    int count(Node* root) {
        if (root == NULL)
            return 0;

        return 1 + count(root->left) + count(root->right);
    }

    bool CBT(Node* root, int index, int totalNodes) {
        if (root == NULL)
            return true;

        if (index >= totalNodes)
            return false;

        return CBT(root->left, 2 * index + 1, totalNodes) &&
               CBT(root->right, 2 * index + 2, totalNodes);
    }

    bool isMaxOrder(Node* root) {
        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return true;

        // Only left child exists
        if (root->right == NULL)
            return (root->data >= root->left->data);

        // Both children exist
        return (root->data >= root->left->data &&
                root->data >= root->right->data &&
                isMaxOrder(root->left) &&
                isMaxOrder(root->right));
    }

    bool isHeap(struct Node* tree) {
        int totalNodes = count(tree);

        return CBT(tree, 0, totalNodes) && isMaxOrder(tree);
    }
};