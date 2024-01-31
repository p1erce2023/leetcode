class Solution(object):
    def canJump(self, nums):
        """
        classic problem
        :type nums: List[int]
        :rtype: bool
        """
        i, limit = 0, 0
        n = len(nums) - 1
        while i <= limit < n:
            t = i + nums[i]
            if t > limit:
                limit = t
            i += 1
        if limit >= n:
            return True
        return False


s = Solution()
print s.canJump([2,3,1,1,4])  # true
print s.canJump([3,2,1,0,4])  # false