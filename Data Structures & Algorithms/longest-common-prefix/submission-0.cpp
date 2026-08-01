class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].length();
        for(auto &s : strs)
            minLen = min(minLen, (int)s.length());

        string ans;
        for(int i = 0; i < minLen; i++) {
            char c = strs[0][i];

            for(string s : strs) {
                if(s[i] != c)
                    return ans;
            }

            ans.push_back(c);
        }

        return ans;
    }
};