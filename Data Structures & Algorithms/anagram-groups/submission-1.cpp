class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;

        for(auto &str : strs) {
            auto h = hash(str);
            cout << h << endl;

            if(mp.find(h) == mp.end()) {
                mp[h] = res.size();
                res.push_back({});
            }

            res[mp[h]].push_back(str);
        }

        return res;
    }

    string hash(string str) {
        int freq[26] {0};
        string ans;

        for(auto c : str)
            freq[c - 'a']++;

        for(int i = 0; i < 26; i++) {
            ans.append(to_string(freq[i]));
            ans.append("#");
        }

        return ans;
    }
};





