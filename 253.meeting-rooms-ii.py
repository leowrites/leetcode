"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        # key insight is while there is a meeting.start smaller 
        # than the current end time, we need to add more meetings. 
        # otherwise, it means a meeting has completed so we can
        # set the earliest ending meeting to the next end time
        intervals.sort(key=lambda x: x.start)
        start = [interval.start for interval in intervals]
        intervals.sort(key=lambda x: x.end)
        end = [interval.end for interval in intervals]
        count = 0
        maxRooms = 0
        i = j = 0
        while i < len(start) and j < len(end):
            if start[i] < end[j]:
                count += 1
                i += 1
                maxRooms = max(maxRooms, count)
            else:
                count -= 1
                j += 1
        return maxRooms