class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # dp 1 dimension + 1 extra
        m, n = len(t), len(s)
        if m > n:
            return 0
        dp = [0] * (m + 1)
        dp[0] = 1
        for i in xrange(n):
            for j in xrange(m - 1, -1, -1):
                if s[i] == t[j]:
                    dp[j + 1] += dp[j]
            # print dp[1:]
        return dp[-1]

        # dp 2 dimension
        m, n = len(t), len(s)
        if m > n:
            return 0
        dp = [[0] * (m + 1) for x in xrange(n + 1)]
        for r in xrange(n + 1):
            dp[r][0] = 1
        # dp(i, j) num of t[:j] in s[:i]
        # dp(i+1, j+1) = dp(i, j+1) + dp(i, j) if s[i+1] == t[j+1]
        #              = dp(i, j+1) else
        for j in xrange(m):
            for i in xrange(j, n):
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j] if s[i] == t[j] else dp[i][j + 1]
        for row in dp[1:]:
            for col in row[1:]:
                print col,
            print
        return dp[-1][-1]


s = Solution()
test = [
    ('cabab', 'ab'),  # 3
    ('abd', 'abc'),  # 0
    ('cababba', 'ab'),  # 5
    ('rabbbit', 'rabbit'),  # 3
    ('rabbbit', 'rabit'),  # 3
    ('aaaaa', 'aa'),  # 10
]
for a, b in test:
    print s.numDistinct(a, b)
