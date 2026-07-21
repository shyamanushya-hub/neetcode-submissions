class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        subset(nums, 0, curr, res);
        return res;
    }

    void subset(vector<int>& nums, int i, 
                 vector<int>& curr, 
                 vector<vector<int>>& res) 
    {
        if(i > nums.size())
            return;

        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }

        subset(nums, i+1, curr, res);
        curr.push_back(nums[i]);
        subset(nums, i+1, curr, res);
        curr.pop_back();
    }
};
