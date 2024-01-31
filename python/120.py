class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        # same 2-d dp -> 1-d dp, consider loop direction
        if not triangle:
            return 0
        n = len(triangle)
        dp = [2147483647] * n
        dp[0] = triangle[0][0]
        for i in xrange(1, n):
            dp[i] = dp[i - 1] + triangle[i][i]
            for j in xrange(i - 1, 0, -1):
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j]
            dp[0] = dp[0] + triangle[i][0]
        return min(dp)

s = Solution()
triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
# triangle = [[-1], [-2, -3]]
print s.minimumTotal(triangle)
