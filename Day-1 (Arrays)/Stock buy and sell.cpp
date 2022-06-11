// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int minPrice = INT_MAX, profit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
      // In minPrice variable we store the minimum price
      // that we find on each and every iteration
      minPrice = min(prices[i], minPrice);

      // We calculate the maximum profit,
      // by taking the maximum out of the previous profit or the current profit
      // which is calculated by subtracting the current price with the
      // minimum recorded price as of the current iteration
      profit = max(profit, prices[i] - minPrice);
    }

    return profit;
  }
};

// Time Complexity - O(n)
// Space Complexity - O(1)