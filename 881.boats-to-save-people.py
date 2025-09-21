#
# @lc app=leetcode id=881 lang=python3
#
# [881] Boats to Save People
#

# @lc code=start
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        s, e = 0, len(people) - 1
        # if s == e, that person should get its own boat
        res = 0
        people.sort()
        while s <= e:
            if people[s] + people[e] > limit:
                e -= 1
            else:
                s += 1
                e -= 1
            res += 1
        return res

        
# @lc code=end

