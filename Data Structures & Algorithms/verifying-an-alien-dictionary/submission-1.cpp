class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> alpha;
        for(int i = 0; i < order.length(); i++) {
            alpha[order[i]] = i;
        }

        for(int i = 0; i < words.size()-1; i++) {
            int j = 0;
            bool isSorted = false;
            while(j < words[i].length() && j < words[i+1].length()){
                if(alpha[words[i][j]] == alpha[words[i+1][j]]) {
                    j++;
                    continue;
                }
                else if(alpha[words[i][j]] < alpha[words[i+1][j]]) {
                    j++;
                    isSorted = true;
                    break;
                }
                else
                    return false;
            }

            if(!isSorted && (words[i].length() > words[i+1].length()))
                return false;
        }

        return true;
    }
};