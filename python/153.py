class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # this is O(n), solve 153 and 154
        # but in fact this could be solved in O(lg(n))
        if not nums:
            return None
        n = len(nums)
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                return nums[i]
        return nums[0]


s = Solution()
print(s.findMin([4, 5, 6, 7, 0, 1, 2]))
