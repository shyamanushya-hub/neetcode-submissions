class Solution {
public:
    bool validPalindrome(string s) {
        bool deleted = false;
        int l = 0;
        int r = s.length()-1;

        while(l < r){
            if(s[l] != s[r])
                return isPalindrome(s.substr(l+1, r-l)) || isPalindrome(s.substr(l, r-l));  
            l++; r--;
        }

        return true;
    }

    bool isPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};