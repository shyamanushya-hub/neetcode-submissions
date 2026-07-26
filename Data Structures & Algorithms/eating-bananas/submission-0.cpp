class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e {0};
        for(auto p : piles)
            e = max(e, p);

        int k {e};
        while(s <= e) {
            int c = s + (e-s) / 2;
            long long hours{0};
            for(auto p : piles) {
                //a += ceil(double(p)/double(c));
                hours += (p+c-1LL) / c;
            }
            if(hours <= h){
                k = c;
                e = c-1;
            }
            else
                s = c+1;
        }

        return k;
    }
};
