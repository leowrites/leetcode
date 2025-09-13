#
# @lc app=leetcode id=338 lang=python3
#
# [338] Counting Bits
#

# @lc code=start
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = []
        for i in range(n + 1):
            k = i
            count = 0
            while k > 0:
                count += k & 1
                k >>= 1
            ans.append(count)
        return ans
        
# @lc code=end

