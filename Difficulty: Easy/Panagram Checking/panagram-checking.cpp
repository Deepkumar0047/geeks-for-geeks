class Solution {
  public:
    bool checkPangram(string& s) {
        set<char>st;
        for(char ch:s){
            if(isalpha(ch))
            st.insert(tolower(ch));
        }
        return st.size() == 26;
    }
};