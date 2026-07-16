class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i {1};
        int ones {0};
        while(i) {
            if(i & n) {
                ++ones;
            }

            i = i << 1;
        }

        return ones;
    }
};
