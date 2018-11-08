// Say you have an array for which the ith element is the price of a given stock
// on day i.  Design an algorithm to find the maximum profit. You may complete
// at most two transactions.  Note: You may not engage in multiple transactions
// at the same time (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> profit(n, 0);
        int max_price = prices[n-1];
        for(int i = n-2; i >= 0; --i) {
            if(prices[i] > max_price)    max_price = prices[i];
            profit[i] = max(profit[i+1], max_price-prices[i]);
        }
        int min_price = prices[0];
        for(int i = 1; i < n; ++i) {
            if(prices[i] < min_price)    min_price = prices[i];
            profit[i] = max(profit[i-1], profit[i] + (prices[i]-min_price));
        }
        return profit[n-1];
    }
};
