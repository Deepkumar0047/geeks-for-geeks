class Solution {
public:
    char nonRepeatingChar(string &s) {

        unordered_map<char, int> mp;

        for (char ch : s)
            mp[ch]++;

        for (char ch : s) {

            if (mp[ch] == 1)
                return ch;
        }

        return '$';
    }
};