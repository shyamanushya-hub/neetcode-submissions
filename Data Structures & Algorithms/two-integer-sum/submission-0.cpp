class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res(2, -1);
        for(int i = 0; i < nums.size(); ++i) {
            if(um.find(target-nums[i]) != um.end()) {
                res[0] = um[target-nums[i]];
                res[1] = i;
                break;
            }
            else {
                um[nums[i]] = i;
            }
        }

        return res;
    }
};
