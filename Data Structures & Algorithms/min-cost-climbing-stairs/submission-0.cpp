class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mem(cost.size(), -1);
        int zero = climb(cost, mem, 0);
        int one = climb(cost, mem, 1);

        return min(zero, one);
    }

    int climb(vector<int>& cost, vector<int>& mem, int curr) {
        if(curr < 0 || curr >= cost.size())
            return 0;

        if(mem[curr] != -1)
            return mem[curr];

        int one = climb(cost, mem, curr+1);
        int two = climb(cost, mem, curr+2);

        mem[curr] = min(one, two) + cost[curr];

        return mem[curr];
    }
    
};
