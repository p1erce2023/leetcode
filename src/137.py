class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = 0, 0
        for c in nums:
            b = ~a & (b^c)
            a = ~b & (a^c)
        return b


s = Solution()
print(s.singleNumber([3,3,3,2]))
