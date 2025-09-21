#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        bought = prices[0]
        maxProfit = 0
        for i in range(1, len(prices)):
            p = prices[i]
            if p < bought:
                bought = p
                continue
            maxProfit = max(maxProfit, p - bought)
        return maxProfit
        
# @lc code=end

