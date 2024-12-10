class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0, current_profit = 0;
        
        // Using sliding window technique
        // 1) check if the current day is the lowest
        // 2) check if current day - mininum day is greater than current max profit
        for (int day = 1; day < prices.size(); day++) {
            current_profit = prices[day]-min;
            if (prices[day] < min && day < prices.size() - 1) {
                min = prices[day];
            }
            else if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }   
        return max_profit;
    }
};