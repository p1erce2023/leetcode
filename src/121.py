class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        _min, _max, _gap = prices[0], prices[0], 0
        for p in prices:
            if p < _min:
                _min = _max = p
            elif p > _max:
                _max = p
                _gap = max(p - _min, _gap)
        return _gap


s = Solution()
print s.maxProfit([3, 2, 6, 5, 0, 3])
print s.maxProfit([7, 1, 5, 3, 6, 4])
print s.maxProfit([7, 6, 4, 3, 1])
