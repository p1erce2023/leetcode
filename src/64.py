class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        matrix = [[0 for _ in range(n)] for _ in range(m)]
        matrix[0][0] = grid[0][0]
        for j in range(1, m):  # initial column 0
            matrix[j][0] = matrix[j-1][0] + grid[j][0]
        for i in range(1, n):  # initial row 0
            matrix[0][i] = matrix[0][i-1] + grid[0][i]
        for j in range(1, m):
            for i in range(1, n):
                matrix[j][i] = min(matrix[j-1][i], matrix[j][i-1]) + grid[j][i]
        return matrix[-1][-1]

s = Solution()
print s.minPathSum([[1,3,4],[2,5,6],[1,12,1]])
