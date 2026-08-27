class Solution {
public:

    struct Node {
        int freq;
        int idx;
        Node *left, *right;

        Node(int f, int i) {
            freq = f;
            idx = i;
            left = right = NULL;
        }
    };

    struct Compare {
        bool operator()(Node* a, Node* b) {
            if (a->freq != b->freq)
                return a->freq > b->freq;

            return a->idx > b->idx;
        }
    };

    void preorder(Node* root, string code, vector<string>& ans) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(code);
            return;
        }

        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f) {

        int n = S.size();

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < n; i++) {
            pq.push(new Node(f[i], i));
        }

        // Only one character
        if (n == 1) {
            return {"0"};
        }

        while (pq.size() > 1) {

            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            Node* parent = new Node(
                left->freq + right->freq,
                min(left->idx, right->idx)
            );

            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        vector<string> ans;

        preorder(pq.top(), "", ans);

        return ans;
    }
};