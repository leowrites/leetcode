#
# @lc app=leetcode id=50 lang=python3
#
# [50] Pow(x, n)
#

# @lc code=start
class Solution:
    def myPow(self, x: float, n: int) -> float:
        # We do not need memoization because the subproblems are not overlapping.
        # Each n visited is different along the call path.
        # helper is called at most once per level (helper(x, n // 2) or helper(x, n - 1))
        def helper(x, n):
            if n == 0: 
                return 1
            elif n == 1: 
                return x
            elif n % 2 == 0:
                res = helper(x, n // 2)
                return res * res
            else:
                return x * helper(x, n - 1)
        res = helper(x, abs(n))
        return res if n >= 0 else 1 / res
        
# @lc code=end

