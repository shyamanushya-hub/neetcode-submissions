class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        string ans{""};
        int i = 0;
        int j = 0;
  
        while (i < l1 || j < l2){
            if(i < l1) ans += word1[i++];
            if(j < l2) ans += word2[j++];
        }

        return ans;
    }
};