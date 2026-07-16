class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(auto &n : nums)
        {
            if(us.find(n) != us.end())
                return true;

            us.insert(n);
        }

        return false;
    }
};