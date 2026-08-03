class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char alpha[26];
        for(int i = 0; i < order.length(); i++) {
            alpha[order[i] - 'a'] = i;
        }

        int n = words.size();
        for(int i = 0; i < n-1; i++) {
            bool isSorted = false;
            const string& w1 = words[i];
            const string& w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());
            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    if(alpha[w1[j]-'a'] > alpha[w2[j] - 'a'])
                        return false;

                    isSorted = true;
                    break;
                }
            }


            if(!isSorted && w1.length() > w2.length())
                return false;
        }

        return true;
    }
};