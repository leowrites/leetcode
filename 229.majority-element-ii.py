#
# @lc app=leetcode id=229 lang=python3
#
# [229] Majority Element II
#

# @lc code=start
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1, cand2 = None, None
        count1, count2 = 0, 0
        for n in nums:
            if n == cand1:
                count1 += 1
            elif n == cand2:
                count2 += 1
                continue
            elif count1 == 0:
                cand1 = n
                count1 += 1
            elif count2 == 0:
                cand2 = n
                count2 += 1
            else:
                # why should we decrement both here?
                # if the current number does not match any, 
                # the "majority-ness" of both candidates are being
                # challenged. To keep counts balanced, reduce
                # both
                count1 -= 1
                count2 -= 1
        req = len(nums) // 3
        count1, count2 = 0, 0
        for n in nums:
            if n == cand1:
                count1 += 1
            elif n == cand2:
                count2 += 1
        res = []
        if count1 > req:
            res.append(cand1)
        if count2 > req:
            res.append(cand2)
        return res


        
# @lc code=end

