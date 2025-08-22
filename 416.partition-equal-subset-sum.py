#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#

# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # is there a way to sum up to sum(nums) / 2?
        # state: num should either be in the set or not
        # the other set: sum(nums) - nums[i]
        # at index n: should include n in left if there is a way, starting at n - 1,
        # to sum up to (sum(nums) / 2) - nums[n]?
        # if yes, then return true, otherwise, return false
        # dp[i] = true if dp[half - nums[i]] else false
        # if adding current element will reach curr?
        # if adding curr > half, return either false or dp[i - 1] (not including current index)
        n = len(nums)
        half = sum(nums) / 2
        halfInt = int(half)
        if halfInt != half:
            return False
        memo = [[False] * (n + 1) for _ in range(halfInt + 1)]
        visited = [[False] * (n + 1) for _ in range(halfInt + 1)]
        def canSumTo(goal, index):
            if goal < 0 or index < 0:
                return False
            if goal == 0:
                memo[goal][index] = True
                return True
            if visited[goal][index]:
                return memo[goal][index]
            visited[goal][index] = True
            memo[goal][index] = canSumTo(goal, index - 1) or canSumTo(goal - nums[index], index - 1)
            return memo[goal][index]
        return canSumTo(halfInt, n - 1)


# @lc code=end

