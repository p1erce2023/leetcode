# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return "[%s,%s]" % (self.start, self.end)


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        # time complexity: O(n*log(n)), using sort
        re = []
        for interval in sorted(intervals, key=lambda item: item.start):
            if not re or interval.start > re[-1].end:
                re.append(interval)
            else:
                re[-1].end = max(interval.end, re[-1].end)
        return re


s = Solution()
import json
print json.dumps([str(i) for i in s.merge([Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)])])
print json.dumps([str(i) for i in s.merge([Interval(4,20), Interval(1,3), Interval(8,10), Interval(15,18)])])
