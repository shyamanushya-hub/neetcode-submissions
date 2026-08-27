class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        int curr {0};

        combination(candidates, ans, arr, curr, 0, target);
        return ans;
    }

    void combination(vector<int>& candidates, vector<vector<int>>& ans, 
                    vector<int>& arr, int &curr, int i, int target) 
    {
        if(curr == target) {
            ans.push_back(arr);
            return;
        }

        if(i >= candidates.size() || curr > target)
            return;

        arr.push_back(candidates[i]);
        curr += candidates[i];
        combination(candidates, ans, arr, curr, i+1, target);
        arr.pop_back();
        curr -= candidates[i];

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        combination(candidates, ans, arr, curr, i+1, target);
    }       
    
};
