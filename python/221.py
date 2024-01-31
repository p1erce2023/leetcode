# -*- coding: utf-8 -*-
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # dp_up[i, j] = 1 + dp[i - 1, j] if x[i, j]
        # dp_left[i, j] = 1 + dp[i, j - 1] if x[i, j]
        # dp_square[i, j] = dp_square[i-1, j-1] + 1
        #    if x[i, j] and dp_left[i, j-1] >= dp_square[i-1, j-1] and
        #    dp_up[i-1, j] >= dp_square[i-1, j-1]
        # n 行 m 列
        n = len(matrix)
        if not n:
            return 0
        m = len(matrix[0])
        # up, left, square bundle
        dp = [[[0, 0, 0] for _ in range(m + 1)] for _ in range(n + 1)]
        for i in range(1, 1 + n):
            for j in range(1, 1 + m):
                if int(matrix[i - 1][j - 1]):
                    dp[i][j][0] = 1 + dp[i - 1][j][0]
                    dp[i][j][1] = 1 + dp[i][j - 1][1]
                    dp[i][j][2] = 1 + min(dp[i - 1][j - 1][2], dp[i][j - 1][1], dp[i - 1][j][0])
        # for row in dp[1:]:
        #     print(row[1:])
        x = max(item[2] for row in dp for item in row)
        return x * x


s = Solution()
print(s.maximalSquare([
    ['1', '0', '1', '0', '0'],
    ['1', '0', '1', '1', '1'],
    ['1', '1', '1', '1', '1'],
    ['1', '0', '0', '1', '0']]))
print(s.maximalSquare([
    ['1', '1'],
    ['1', '1']]))
print(s.maximalSquare([
    ["0", "0", "0", "1"],
    ["1", "1", "0", "1"],
    ["1", "1", "1", "1"],
    ["0", "1", "1", "1"],
    ["0", "1", "1", "1"]]))
