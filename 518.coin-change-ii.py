#
# @lc app=leetcode id=518 lang=python3
#
# [518] Coin Change II
#

# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # each coin does not need to be used, but it can be used multiple times
        # dim 1: amount
        # dim 2: coins
        # dp[remaining, index] = for each i, c in enumerate(coins), sum of number of ways to make up dp[remaining - c, i]
        n = len(coins)
        dp = [[0] * (n + 1) for _ in range(amount + 1)]
        for remain in range(amount + 1):
            for index in range(n):
                if remain == 0:                
                    dp[remain][index] = 1
                elif index == 0:
                    # if remain / coins[index] is divisible, we should still be able to use it
                    dp[remain][index] = 1 if remain % coins[index] == 0 else 0
                else:
                    # either don't use current coin, or use current coin
                    if remain - coins[index] >= 0:
                        dp[remain][index] = dp[remain][index - 1] + dp[remain - coins[index]][index]
                    else:
                        dp[remain][index] = dp[remain][index - 1]
        return dp[amount][n - 1]

        
# @lc code=end

