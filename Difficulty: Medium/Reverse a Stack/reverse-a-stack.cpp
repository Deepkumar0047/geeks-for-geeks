class Solution {
public:

    // Insert an element at the bottom of stack
    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    void reverseStack(stack<int>& st) {
        // Base case
        if (st.empty())
            return;

        int x = st.top();
        st.pop();

        // Reverse remaining stack
        reverseStack(st);

        // Put removed element at bottom
        insertAtBottom(st, x);
    }
};