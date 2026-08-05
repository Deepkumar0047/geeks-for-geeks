class Solution {
public:
    void removeCharacter(string &s, char c) {

        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != c) {
                s[j++] = s[i];
            }
        }

        s.resize(j);
    }
};