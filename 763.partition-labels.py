#
# @lc app=leetcode id=763 lang=python3
#
# [763] Partition Labels
#

# @lc code=start
import collections
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # count the number of occurrences for each character, maintain a set of currently adding elements
        # For each index i, while counter[s[i]] > 0, add it to the current partition. At one point,
        # the set should be empty, so we finish start a new partition
        currSet = set()
        partitionSize = 0
        res = []
        counter = collections.Counter(s)

        for i in range(len(s)):
            c = s[i]
            if counter[c] > 0:
                currSet.add(c)
                partitionSize += 1
            counter[c] -= 1
            if counter[c] == 0:
                currSet.remove(c)
            if len(currSet) == 0:
                res.append(partitionSize)
                partitionSize = 0
        return res
            
        
# @lc code=end

