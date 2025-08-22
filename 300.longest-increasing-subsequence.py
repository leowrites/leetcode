#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
#

# @lc code=start
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # start at back
        # at each index, look at all values behind it
        # select the one such that nums[i] < nums[j] and gives the highest LIS
        # O(n^2)

        # Key lessons:
        #   - don't be scared to loop over all the subsequent elements
        n = len(nums)
        lis = [1] * n
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if nums[i] < nums[j]:
                    lis[i] = max(lis[i], lis[j] + 1)
        return max(lis)

        
# @lc code=end

