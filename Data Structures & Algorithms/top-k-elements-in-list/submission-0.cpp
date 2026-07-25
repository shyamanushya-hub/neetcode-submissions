class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2001,0);
        int maxf {0};

        for(auto n : nums) {
            freq[n+1000]++;
            maxf = max(maxf, freq[n+1000]);
        }

        vector<vector<int>> buckets(maxf+1);
        for(int i = 0; i < 2001; i++){
            if(freq[i] > 0) {
                buckets[freq[i]].push_back(i - 1000);
            }
        }

        vector<int> ans;
        for(int i = maxf; i >= 1 && ans.size() < k; i--) {
            for(auto j : buckets[i]) {
                ans.push_back(j);
                if(ans.size() >= k)
                    break;
            }
        }
        return ans;
    }
};
