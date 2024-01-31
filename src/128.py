class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        u = {}
        for i in nums:
            if u.get(i):
                continue
            u[i] = 1
            if u.get(i - 1) and u.get(i + 1):
                u[i - u[i - 1]] = u[i + u[i + 1]] = u[i - 1] + u[i + 1] + 1
            elif u.get(i - 1):
                u[i] = u[i - u[i - 1]] = u[i - 1] + 1
            elif u.get(i + 1):
                u[i] = u[i + u[i + 1]] = u[i + 1] + 1
        return max(u.values())


s = Solution()
print(s.longestConsecutive([]))
print(s.longestConsecutive([100, 4, 200, 1, 3, 2]))
print(s.longestConsecutive([4, 2, 2, -4, 0, -2, 4, -3, -4, -4, -5, 1, 4, -9, 5, 0, 6, -8, -1, -3, 6, 5, -8, -1, -5, -1, 2, -9, 1]))  # noqa
