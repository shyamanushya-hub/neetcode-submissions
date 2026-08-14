class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s <= e){
            int m = (e+s) / 2;
            if(nums[m] == t) return m;
            if(nums[s] == t) return s;
            if(nums[e] == t) return e;

            if(nums[s] < nums[m]){
                if(t > nums[s] && t < nums[m]) e = m-1;
                else s = m+1;
            }
            else{
                if(t > nums[m] && t < nums[e]) s = m+1;
                else e = m-1;
            }
        }
        return -1;
    }
};
