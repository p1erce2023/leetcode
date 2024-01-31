class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i, j, n = 0, 0, len(nums)
        min_w = n + 1
        x = 0
        while j < n:
            while x >= s:
                min_w = min(min_w, j - i)
                if min_w == 1:
                    return 1
                x -= nums[i]
                i += 1
            while x < s and j < n:
                x += nums[j]
                j += 1
        while x >= s and i < n:
            min_w = min(min_w, j - i)
            if min_w == 1:
                return 1
            x -= nums[i]
            i += 1
        return min_w if min_w != n + 1 else 0


s = Solution()
print(s.minSubArrayLen(7, [2,3,1,2,4,3]))
print(s.minSubArrayLen(7, [2,3,1,2,4,2,1]))
print(s.minSubArrayLen(7, [2]))
print(s.minSubArrayLen(7, []))
print(s.minSubArrayLen(7, [18]))
print(s.minSubArrayLen(7, [7]))
