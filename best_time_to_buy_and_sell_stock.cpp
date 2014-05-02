class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxProfit(vector<int> &prices) {
        int min = 0; // index for current minimum price
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < prices[min]) {
                min = i;
            }
            int profit = prices[i] - prices[min];
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};
