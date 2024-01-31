class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if not m:
            return []
        n = len(matrix[0])
        b_up, b_down, b_left, b_right = -1, m, -1, n
        l = m * n
        r = [0] * l
        d_up, d_down, d_left, d_right = (-1, 0), (1, 0), (0, -1), (0, 1)
        direction = d_right
        row, col, i = 0, 0, 0
        while i < l:
            r[i] = matrix[row][col]        
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
        return r

s = Solution()
print s.spiralOrder([[1,2,3],[4,5,6],[7,8,9]])  # [1,2,3,6,9,8,7,4,5]
print s.spiralOrder([[1]])
print s.spiralOrder([[1,3],[4,5]])
print s.spiralOrder([[1,2,3,7],[4,5,6,8]])