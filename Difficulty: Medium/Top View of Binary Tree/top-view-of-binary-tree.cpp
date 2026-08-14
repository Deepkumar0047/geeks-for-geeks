/*
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
};
*/

class Solution {
public:
    vector<int> topView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        // horizontal distance, node
        map<int, int> mp;

        // node, horizontal distance
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            auto current = q.front();
            q.pop();

            Node* node = current.first;
            int hd = current.second;

            // First node at this horizontal distance
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            // Left child -> hd - 1
            if (node->left) {
                q.push({node->left, hd - 1});
            }

            // Right child -> hd + 1
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // map automatically gives left to right order
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};