class Solution {
public:
    bool isPalindrome(string str) {
        int s = 0;
        int e = str.length() - 1;

        while(s <= e && !isalnum(str[s]))
            ++s;
        while(e >= 0 && !isalnum(str[e]))
            --e;

        while (s <= e) {
            while(!isalnum(str[s]))
                ++s;
            while(!isalnum(str[e]))
                --e;
                
            if(tolower(str[s]) != tolower(str[e]))
                return false;

            ++s;
            --e;
        }

        return true;
    }
};
