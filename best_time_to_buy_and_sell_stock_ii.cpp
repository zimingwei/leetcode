class Solution {
public:
    // Greedy: buy at valley value and sell at peak value
    // Time: O(n)
    // Space: O(1)
    int maxProfit(vector<int> &prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                sum += diff;
            }
        }
        return sum;
    }
};
