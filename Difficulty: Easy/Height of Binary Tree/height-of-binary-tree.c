/*
Definition for Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}