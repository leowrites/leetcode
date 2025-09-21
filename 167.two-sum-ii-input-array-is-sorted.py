#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        s, e = 0, len(numbers) - 1
        # s < e, because we are not allowed to use the same element twice
        while s < e:
            if numbers[s] + numbers[e] == target:
                return [s, e]
            if numbers[s] + numbers[e] > target:
                e -= 1
            else:
                s += 1
            
        
# @lc code=end

