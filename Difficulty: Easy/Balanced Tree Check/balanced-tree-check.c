/* Structure of binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
*/
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = height(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct Node* root) {
    return height(root) != -1;
}