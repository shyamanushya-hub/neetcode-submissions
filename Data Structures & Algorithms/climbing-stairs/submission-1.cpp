class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return climbStairs_(n, mem);
    }

    int climbStairs_(int n, vector<int>& mem) {
        if(n < 0)
            return 0;
        
        if(n == 0)
            return 1;
        
        if(mem[n] != -1)
            return mem[n];

        int one = climbStairs_(n-1, mem);
        int two = climbStairs_(n-2, mem);
        mem[n] = one + two;
        return one + two;
    }
};
