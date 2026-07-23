class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int curr {0};

        combination(nums, ans, arr, curr, 0, target);
        return ans;
    }

    void combination(vector<int>& nums, vector<vector<int>>& ans, 
                    vector<int>& arr, int &curr, int i, int target) {
        if(i >= nums.size())
            return;

        if(curr == target)
        {
            ans.push_back(arr);
            return;
        }
        else if( curr > target)
            return;

        arr.push_back(nums[i]);
        curr += nums[i];
        combination(nums, ans, arr, curr, i, target);
        arr.pop_back();
        curr -= nums[i];
        combination(nums, ans, arr, curr, i+1, target);
    }
};
