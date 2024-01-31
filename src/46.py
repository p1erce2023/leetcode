class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # already in memory..
        q = []
        def p(nums, i, q):
            n = len(nums)
            if i == n - 1:
                q.append(nums[:])
            for j in xrange(i, n):
                nums[i], nums[j] = nums[j], nums[i]
                p(nums, i+1, q)
                nums[i], nums[j] = nums[j], nums[i]
        p(nums, 0, q)
        return q

s = Solution()
print s.permute([1,2,3])

