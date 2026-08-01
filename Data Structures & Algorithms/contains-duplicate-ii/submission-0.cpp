class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        auto l = nums.size();
        for(int i = 0; i < l; i++) {
            if(m.find(nums[i]) != m.end() && (i-m[nums[i]] <= k))
                return true;
            
            m[nums[i]] = i;
        }

        return false;
    }
};