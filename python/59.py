class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if not n:
            return []
        b_up, b_down, b_left, b_right = -1, n, -1, n
        l = n * n
        matrix = [[0]*n for _ in xrange(n)]
        d_up, d_down, d_left, d_right = (-1, 0), (1, 0), (0, -1), (0, 1)
        direction = d_right
        row, col, i = 0, 0, 1
        while i <= l:
            matrix[row][col] = i
            try_row, try_col = row + direction[0], col + direction[1]
            if try_col >= b_right:
                direction = d_down
                b_up = row
            elif try_col <= b_left:
                direction = d_up
                b_down = row
            elif try_row >= b_down:
                direction = d_left
                b_right = col
            elif try_row <= b_up:
                direction = d_right
                b_left = col
            row, col = row + direction[0], col + direction[1]
            i += 1
        return matrix

s = Solution()
print s.generateMatrix(4)