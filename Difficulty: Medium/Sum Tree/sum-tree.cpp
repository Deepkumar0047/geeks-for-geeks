/* Definition for Node
class Node {
public:
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
    pair<bool, int> solve(Node* root) {
        
        if (root == NULL)
        return {true, 0};

        if (root->left == NULL && root->right == NULL)
        return {true, root->data};

        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);

        bool isSumTree = left.first &&
        right.first &&
        root->data == left.second + right.second;

        int totalSum = root->data + left.second + right.second;

        return {isSumTree, totalSum};
    }

    bool isSumTree(Node* root) {
        return solve(root).first;
    }
};