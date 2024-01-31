class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        x = 0
        for c in nums:
            x ^= c
        b = 1
        while not b & x:
            b = b << 1
        x, y = 0, 0
        for c in nums:
            if c & b:
                x ^= c
            else:
                y ^= c
        return [x, y]


s = Solution()
print(s.singleNumber([1,2,1,3,2,5]))
