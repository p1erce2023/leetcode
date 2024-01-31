class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # not by myself
        n = len(nums)
        if not n:
            return []
        max_forward = nums.copy()
        max_reverse = nums.copy()
        for i in range(0, n, k):
            gap = min(k, n - i)
            for j in range(1, gap):
                max_forward[i+j] = max(max_forward[i+j-1], nums[i+j])
                max_reverse[i+gap-1-j] = max(max_reverse[i+gap-j], nums[i+gap-1-j])
        return [max(max_forward[i+k-1], max_reverse[i]) for i in range(n - k + 1)]


s = Solution()
print(s.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))  # [3,3,5,5,6,7]
print(s.maxSlidingWindow([3, 4], 1))
