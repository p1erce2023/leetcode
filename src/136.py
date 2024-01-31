class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        y = 0
        for i in nums:
            y ^= i
        return y


s = Solution()
print(s.singleNumber([1, 2, 3, 4, 2, 3, 1]))
