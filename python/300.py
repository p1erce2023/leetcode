class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # O(n*log(n))
        if not nums:
            return 0
        s = [nums[0]]
        for k in nums[1:]:
            i, j = 0, len(s)
            if k < s[0]:
                s[0] = k
                continue
            elif k > s[-1]:
                s.append(k)
                continue
            while i != j:
                m = (i & j) + ((i ^ j) >> 1)
                if k < s[m]:
                    j = m
                elif k == s[m]:
                    i = m
                    break
                else:
                    i = m + 1
            if i == len(s):
                s.append(k)
            else:
                s[i] = k
        return len(s)

        # O(n^2)
        if not nums:
            return 0
        n = len(nums)
        dp = [1] * n
        for i in xrange(1, n):
            for j in xrange(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            # print dp
        return max(dp)

s = Solution()
print s.lengthOfLIS([2, 2])
print s.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
print s.lengthOfLIS([1, 3, 6, 7, 9, 4, 10, 5, 6])
