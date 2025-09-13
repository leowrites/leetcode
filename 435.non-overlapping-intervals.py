#
# @lc app=leetcode id=435 lang=python3
#
# [435] Non-overlapping Intervals
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort by start time, and keep track of the current end time.
        # when deciding whether to remove interval i, compare interval[i].start against currEnd.
        # if interval[i].start < currEnd:
        #   remove the interval with larger currEnd
        #   increment count by 1, and do not update currEnd
        # else if interval[i].start > currEnd:
        #   update currEnd to interval[i].end
        intervals.sort()
        currEnd = intervals[0][1]
        remove = 0
        for i in range(1, len(intervals)):
            currInterval = intervals[i]
            if currInterval[0] < currEnd:
                remove += 1
                currEnd = min(currEnd, currInterval[1])
            else:
                currEnd = currInterval[1]
        return remove

        
# @lc code=end

