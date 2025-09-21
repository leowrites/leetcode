#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(2, len(nums)):
            if nums[i - 1]  == nums[i]:
                continue
            n = nums[i]
            s = i + 1
            e = len(nums) - 1
            while s < e:
                if nums[s] + nums[e] == -n:
                    res.append([nums[s], nums[e], n])
                    s += 1
                    # this is to make sure we don't add duplicates
                    while s < e and nums[s - 1] == nums[s]:
                        s += 1
                elif nums[s] + nums[e] < -n:
                    s += 1
                else:
                    e -= 1
        return res
        
# @lc code=end

