class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        if not m:
            return 0
        n = len(obstacleGrid[0])
        if not n:
            return 0
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        dp[0][1] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if obstacleGrid[i-1][j-1]:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

s = Solution()
print s.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]])
