class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        # space O(2*min(m, n)), O(2*m) faster
        n, m = len(word1), len(word2)
        # if n < m:
        #     n, m = m, n
        #     word1, word2 = word2, word1
        dp = [range(m+1)]*2 for _ in range(2)]
        for i in xrange(1, n + 1):
            dp = [dp[1], dp[0]]
            dp[1][0] = i
            for j in xrange(1, m + 1):
                if word1[i-1] == word2[j-1]:
                    dp[1][j] = min(dp[0][j]+1, dp[1][j-1]+1, dp[0][j-1])
                else:
                    dp[1][j] = min(dp[0][j]+1, dp[1][j-1]+1, dp[0][j-1]+1)
        return dp[1][m]

        # space O(n*m)
        n, m = len(word1), len(word2)
        dp = [[0 for _ in xrange(m+1)] for _ in xrange(n+1)]
        for i in xrange(m+1):
            dp[0][i] = i
        for i in xrange(n+1):
            dp[i][0] = i
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
                else:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
        print dp[n][m]


s = Solution()
print s.minDistance('gabcde', 'abcdef')
print s.minDistance('abc', 'cdf')
print s.minDistance('a', 'abc')
print s.minDistance('a', 'bcd')
print s.minDistance('gc', 'abgfc')
print s.minDistance('gm', 'abgfc')
print s.minDistance('mk', 'abgfc')
print s.minDistance('bcde', 'ce')
print s.minDistance('bcde', 'f')
print s.minDistance('bcde', 'cef')
