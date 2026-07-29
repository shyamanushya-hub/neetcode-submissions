class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int s = i+1;
            int e = nums.size() - 1;
            int target = -nums[i];

            vector<int> ans(3, -1);
            while(s < e) {
                auto sum = nums[s] + nums[e];
                if(sum == target) {
                    res.push_back({nums[i], nums[s], nums[e]});
                    s++; e--;
                    while(s < e && nums[s] == nums[s-1]) s++;
                    while(s < e && nums[e] == nums[e+1]) e--;
                }
                else if(sum < target)
                    ++s;
                else
                    --e;
            }
        }

        return res;

    }
};
