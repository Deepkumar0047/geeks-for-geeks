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
    Node* delNode(Node* root, int x) {

        if (root == NULL)
            return NULL;

        if (x < root->data) {
            root->left = delNode(root->left, x);
        }

        else if (x > root->data) {
            root->right = delNode(root->right, x);
        }

        else {

            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = root->right;

            while (temp->left != NULL) {
                temp = temp->left;
            }

            root->data = temp->data;

            root->right = delNode(root->right, temp->data);
        }

        return root;
    }
};