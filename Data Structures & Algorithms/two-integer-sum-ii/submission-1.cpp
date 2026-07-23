class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() - 1;

        vector<int> ans(2, -1);
        while(s < e) {
            auto sum = numbers[s] + numbers[e];
            if(sum == target) {
                ans[0] = s+1;
                ans[1] = e+1;
                break;
            }
            else if(sum < target)
                ++s;
            else
                --e;
        }

        return ans;
    }
};
