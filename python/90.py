class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        from collections import Counter
        counter = Counter(nums)
        res = [[]]
        for k, v in counter.iteritems():
            t = []
            for i in xrange(1, v + 1):
                t.extend(r + [k] * i for r in res)
            # print t
            res.extend(t)
        return res

s = Solution()
print s.subsetsWithDup([1, 2])
print s.subsetsWithDup([1, 2, 2])
print s.subsetsWithDup([1, 2, 2, 2])
print len(s.subsetsWithDup([1, 2, 2, 3, 3, 3, 4, 4, 5]))
