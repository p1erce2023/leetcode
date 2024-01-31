class Solution(object):
    def maxSubArray(self, nums):
        """
        classic problem
        :type nums: List[int]
        :rtype: int
        """
        max_sub_sum = -2147483647
        t_sum = 0
        for n in nums:
            t_sum = t_sum + n if t_sum >= 0 else n
            max_sub_sum = max(max_sub_sum, t_sum)
        return max_sub_sum


s = Solution()
print s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]) # 6