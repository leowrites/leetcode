#
# @lc app=leetcode id=309 lang=python3
#
# [309] Best Time to Buy and Sell Stock with Cooldown
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # [1,2,3,0,2]
        # dim1: 3 choices
        # dim2: prices
        # Key insight:
        # If buying i, add -prices[i] to the overall profit.
        # If selling i, add prices[i] to the overall profit
        n = len(prices)
        dp = [[0] * 3 for _ in range(n)]
        cooldown = 0
        buy = 1
        sell = 2
        # how to initialize?
        dp[0][cooldown] = 0
        dp[0][buy] = -prices[0]
        dp[0][sell] = -float('inf')
        for i in range(1, n):
            # cooldown: can only come from sell
            dp[i][cooldown] = max(dp[i-1][cooldown], dp[i-1][sell])
            # buy: buy today if yesterday was cooldown, or hold what we bought yesterday
            dp[i][buy] = max(dp[i - 1][cooldown] - prices[i], dp[i - 1][buy])
            # sell: can only come from buy
            dp[i][sell] = dp[i - 1][buy] + prices[i]
        return max(dp[n - 1])

# @lc code=end

