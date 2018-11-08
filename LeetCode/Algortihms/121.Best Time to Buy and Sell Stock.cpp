class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int max_profit = 0;
        int max_price = prices[prices.size()-1];
        for(int i = prices.size()-1; i >= 0; --i) {
            max_price = max(max_price, prices[i]);
            max_profit = max(max_profit, max_price-prices[i]);
        }
        return max_profit;
    }
};
