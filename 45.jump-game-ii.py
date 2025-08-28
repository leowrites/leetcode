#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#

# @lc code=start
from collections import deque
class Solution:
    def jump(self, nums: List[int]) -> int:
        queue = deque([[0, 0]])
        seen = [False] * len(nums)
        farthest = 0
        while queue:
            i, jumps = queue.popleft()
            if i >= len(nums) - 1:
                return jumps
            if seen[i]:
                continue
            seen[i] = True
            # we shouldn't append everything, should be when the farthest is so far,
            # if it's shorter than no point in appending
            for j in range(farthest + 1, i + nums[i] + 1):
                farthest = j
                if j >= len(nums) - 1:
                    return jumps + 1
                if seen[j]:
                    continue
                queue.append([j, jumps + 1])
                    
            
# @lc code=end

