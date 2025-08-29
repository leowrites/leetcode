#
# @lc app=leetcode id=846 lang=python3
#
# [846] Hand of Straights
#

# @lc code=start
import collections
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        if n // groupSize != int(n / groupSize):
            return False
        # just sort/count? guarantees we can find the next consecutive number quickly
        # we should start from the beginning and try to make groupSize groups, since we need consecutive,
        # they must be num1 + j for j in groupSize. We should do this greedily starting from the front 
        # because we always need the prior values to be a part of a group first.
        counter = collections.Counter(hand)
        hand.sort()
        for i in range(n):
            num1 = hand[i]
            if counter[num1] == 0:
                continue
            for j in range(groupSize):
                if counter[num1 + j] == 0:
                    return False
                counter[num1 + j] -= 1
        return True
        
        
# @lc code=end

