/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

*/

class Solution {
public:
    void connect(Node *root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Connect previous node to current node
                if (prev != nullptr) {
                    prev->nextRight = curr;
                }

                prev = curr;

                // Add children to queue
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            // Last node of this level
            prev->nextRight = nullptr;
        }
    }
};