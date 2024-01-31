# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return "[%s,%s]" % (self.start, self.end)

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        # script 2: not only list.remove, count _binary search_ in, also
        n = len(intervals)
        if not n:
            return [newInterval]
        if intervals[0].start > newInterval.end:
            return [newInterval] + intervals
        if intervals[-1].end < newInterval.start:
            return intervals + [newInterval]
        # binary search
        st, ed = 0, n-1
        i = -1
        while st < ed:
            md = (st & ed) + ((st ^ ed) >> 1)
            if intervals[md].end < newInterval.start <= intervals[md+1].end:
                i = md + 1
                break
            elif newInterval.start <= intervals[md].end:
                ed = md
            else:
                st = md + 1
        if st >= ed:
            i = st
        if newInterval.end < intervals[i].start:
            return intervals[:i] + [newInterval] + intervals[i:]
        else:
            intervals[i].start = min(intervals[i].start, newInterval.start)
            if newInterval.end <= intervals[i].end:
                return intervals
            else:
                intervals[i].end = newInterval.end
                re = intervals[:i + 1]
                i += 1
                while i < n:
                    if intervals[i].start > re[-1].end:
                        re += intervals[i:]
                        return re
                    else:
                        re[-1].end = max(re[-1].end, intervals[i].end)
                        i += 1
                return re


        # script 1: slow, maybe its list.remove's fault
        i, n = 0, len(intervals)
        merge = False
        while i < n:
            if merge:
                if intervals[i].start > intervals[i-1].end:
                    return intervals
                else:
                    intervals[i-1].end = max(intervals[i].end, intervals[i-1].end)
                    intervals.remove(intervals[i])
                    n -= 1
                    continue
            else:
                if newInterval.start <= intervals[i].end:
                    if newInterval.end < intervals[i].start:
                        intervals.insert(i, newInterval)
                        return intervals
                    else:
                        intervals[i].start = min(newInterval.start, intervals[i].start)
                        if newInterval.end <= intervals[i].end:  # i.start <= new_i.end <= i.end
                            return intervals
                        else:  # i.start < i.end < new_i.end
                            intervals[i].end = newInterval.end
                            merge = True
                i += 1
        if not merge:
            intervals.append(newInterval)
        return intervals


s = Solution()
import json
print json.dumps([str(i) for i in s.insert([Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)], Interval(4, 9))])  # [1,2],[3,10],[12,16]
print json.dumps([str(i) for i in s.insert([], Interval(11,13))])
print json.dumps([str(i) for i in s.insert([Interval(1,3), Interval(6,9)], Interval(11,13))])
print json.dumps([str(i) for i in s.insert([Interval(1,3), Interval(6,9)], Interval(2,5))])  # [1,5],[6,9]
