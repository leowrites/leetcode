class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        # sort by start time, if the current start is lower than
        # previous end, return False
        intervals.sort(key=lambda interval: interval.start)
        for i in range(1, len(intervals)):
            if intervals[i].start < intervals[i - 1].end:
                return False
        return True