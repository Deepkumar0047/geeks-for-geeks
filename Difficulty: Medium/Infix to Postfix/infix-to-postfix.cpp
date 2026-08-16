class Solution {
public:
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string ans;

        for (char c : s) {

            // Operand
            if (isalnum(c)) {
                ans += c;
            }

            // Opening bracket
            else if (c == '(') {
                st.push(c);
            }

            // Closing bracket
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }

            // Operator
            else {
                while (!st.empty() && st.top() != '(' &&
                       (precedence(st.top()) > precedence(c) ||
                       (precedence(st.top()) == precedence(c) && c != '^'))) {
                    ans += st.top();
                    st.pop();
                }

                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};