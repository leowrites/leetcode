#
# @lc app=leetcode id=1899 lang=python3
#
# [1899] Merge Triplets to Form Target Triplet
#

# @lc code=start
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        # The goal is really to keep taking the maximum possible while staying equal to or below 
        # target, because if any element is larger than target, we cannot merge with that triplet. 
        # While we are equal to or below target, we can continually take the larger element
        n = len(triplets)
        res = [-1, -1, -1]
        for i in range(n):
            curr = triplets[i]
            if curr[0] > target[0] or curr[1] > target[1] or curr[2] > target[2]:
                continue
            res = max(curr[0], res[0]), max(curr[1], res[1]), max(curr[2], res[2])
            if sum(res[k] == target[k] for k in range(3)) == 3:
                return True
        return False

        
# @lc code=end

