class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> mem(nums.size(), 0);

        mem[n-1] = nums[n-1];
        mem[n-2] = nums[n-2];

        int ans = max(nums[n-1], nums[n-2]);

        for(int i = n-3; i >=0; --i) {
            mem[i] = max(nums[i]+mem[i+2], mem[i+1]);
            if(mem[i] > ans)
                ans = mem[i];
        }

        return ans;
    }


};
