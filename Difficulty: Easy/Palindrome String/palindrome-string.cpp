class Solution {
  public:
    bool isPalindrome(string& s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        
        return temp == s;
        
    }
};