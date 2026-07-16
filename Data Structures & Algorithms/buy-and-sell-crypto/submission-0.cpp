class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];

        int profit = 0;
        for(auto p : prices) {
            if(p < buy) {
                if((sell-buy) > profit)
                    profit = sell - buy;
                
                buy = p;
                sell = p;
            }
            else {
                if(p > sell)
                    sell = p;
            }
        }

        if((sell - buy) > profit)
            profit = sell - buy;

        return profit;

    }
};
