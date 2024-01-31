class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if not n:
            return 0
        elif n < 4:
            return max(nums)
        # choose nums[0], cannot select nums[-1]
        dp = [0] * n
        dp[0] = nums[0]
        dp[2] = nums[0] + nums[2]
        for i in range(3, n - 1):
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i]
        # choose nums[1] or nums[2], may select nums[-1]
        dq = [0] * n
        dq[1] = nums[1]
        dq[2] = nums[2]
        for i in range(3, n):
            dq[i] = max(dq[i-2], dq[i-3]) + nums[i]
        return max(dp[-2], dp[-3], dq[-1], dq[-2])


s = Solution()
# print(s.rob([2]))
# print(s.rob([2,3,2,3,2]))
# print(s.rob([1,2,3,1]))
print(s.rob([4,1,2,7,5,3,1]))
# print(s.rob([1, 2, 3, 4, 5, 1, 2, 3, 4, 5]))
