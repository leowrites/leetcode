#
# @lc app=leetcode id=805 lang=python3
#
# [805] Split Array With Same Average
#

# @lc code=start
class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        # when we remove, subtract and we can recompute average
        # current element is either in array 1 or not. If it is, check
        # target - nums[i], i - 1. otherwise, check target, i - 1
        # to see average, the do sum / # of elements in array
        total = sum(nums)
        n = len(nums)
        def isAverageSame(target, index, numInArray):
            if index < 0 or target < 0:
                return False
            if target / numInArray == (sum - target) / (n - numInArray):
                return True
            # if we include the current index in array1
            return isAverageSame(target - nums[index], index - 1, numInArray + 1) or isAverageSame(target, index - 1, numInArray)
        return isAverageSame(total, n, 0)
        
        
# @lc code=end

