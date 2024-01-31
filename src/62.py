import math
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # using dp, dp[][], add is much faster than multiply, O(m*n) space
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

        # O(n) space, interesting solution
        if not m or not n:
            return 0
        cur = [1] * n
        for i in xrange(1, m):
            for j in xrange(1, n):
                cur[j] += cur[j-1]
        return cur[-1]

        # this is (m+n)C(n), the combination number calculation
        return math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1)

        # using math is faster than for & multiply
        if m > n:
            n, m = m, n
        # m is the small one
        s = 1
        for i in range(n+1, n+m):
            s *= i
        for i in range(1, m):
            s /= i
        return s

s = Solution()
print s.uniquePaths(5, 3)
print s.uniquePaths(5, 4)
print s.uniquePaths(6, 3)
