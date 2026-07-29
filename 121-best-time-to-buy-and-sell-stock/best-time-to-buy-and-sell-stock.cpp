class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 , bestBuy = prices[0];
        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - bestBuy;
            maxProfit = max(maxProfit, cost);
            bestBuy  = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};