class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        string ans(l1+l2, 'A');
        int i = 0;
        int j = 0;
        int k = 0;
        bool one = true;
        while(k < l1+l2){
            if(one){
                if(i < l1)
                    ans[k++] = word1[i++];
            }
            else {
                if(j < l2)
                    ans[k++] = word2[j++];
            }
            one = !one;
        }

        return ans;
    }
};