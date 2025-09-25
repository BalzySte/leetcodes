class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        bool bought = false;

        for (int i = 0; i < len - 1; ++i) {
            int day_return = prices[i + 1] - prices[i];
            // std::cout << "day " << i << ": ";

            if (day_return > 0 && bought == false) {
                // buy and pocket the profit
                bought = true;
                profit += day_return;
                // std::cout << "bought for profit " << day_return; 
            } else if (day_return > 0 && bought == true) {
                // keep pocketing the profit
                profit += day_return;
                // std::cout << "collected profit " << day_return;
            } else if (day_return < 0 && bought == false) {
                // keep avoiding losses
            } else if (day_return < 0 && bought == true) {
                // sell to avoid losses
                bought = false;
                // std::cout << "sold";
            }
            // std::cout << std::endl;
        }

        return profit;
    }
};
