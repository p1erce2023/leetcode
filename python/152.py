class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]
        pos, neg, r = 0, 0, nums[0]
        for m in nums:
            if m > 0:
                if pos:
                    pos = pos * m
                else:
                    pos = m
                if neg:
                    neg = neg * m
            elif m < 0:
                if neg:
                    t = neg * m
                else:
                    t = 0
                if pos:
                    neg = pos * m
                else:
                    neg = m
                pos = t
            else:
                pos = neg = 0
            if pos > r:
                r = pos
        return r


s = Solution()
print(s.maxProduct([2, 3, -2, 4]))
print(s.maxProduct([2, 3, -2, -4]))
print(s.maxProduct([-2, 3, -2, 4]))
print(s.maxProduct([2, -5, -2, -4, 3]))
print(s.maxProduct([-2, 0, -1]))
