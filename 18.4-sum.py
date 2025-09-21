#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
class Solution:
    def threeSum(self, start: int, target: int, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(start, len(nums)):
            if i > start and nums[i - 1] == nums[i]:
                continue
            n = nums[i]
            t = target - n
            s = i + 1
            e = len(nums) - 1
            while s < e:
                if nums[s] + nums[e] == t:
                    res.append([nums[s], nums[e], n])
                    s += 1
                    # this is to make sure we don't add duplicates
                    while s < e and nums[s - 1] == nums[s]:
                        s += 1
                elif nums[s] + nums[e] < t:
                    s += 1
                else:
                    e -= 1
        return res

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for i, n in enumerate(nums):
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            s = i + 1
            triplets = self.threeSum(s, target - n, nums)
            for t in triplets:
                res.append([n] + t)
        return res

        
# @lc code=end

