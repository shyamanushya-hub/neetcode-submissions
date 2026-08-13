class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergesort(vector<int>& nums, int s, int e){
        if(s >= e) return;

        int m = s + (e-s)/2;
        mergesort(nums, s, m);
        mergesort(nums, m+1, e);

        int l1 = s;
        int l2 = m+1;

        vector<int> ans;
        while(l1 <= m && l2 <= e) {
            if(nums[l1] <= nums[l2])
                ans.push_back(nums[l1++]);
            else
                ans.push_back(nums[l2++]);
        }

        while(l1 <= m)
            ans.push_back(nums[l1++]);

        while(l2 <= e)
            ans.push_back(nums[l2++]);

        for(int i = s; i <= e; i++)
            nums[i] = ans[i-s];

    }
};