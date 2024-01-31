class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # keep eye for extra space, O(m+n). How O(1) space?
        row, column = set(), set()
        m = len(matrix)
        if not m:
            return matrix
        n = len(matrix[0])
        for i in xrange(m):
            for j in xrange(n):
                if not matrix[i][j]:
                    row.add(i)
                    column.add(j)
        for r in row:
            matrix[r] = [0] * n
        for c in column:
            for r in xrange(m):
                matrix[r][c] = 0
        return

        # O(1), very smart. the goal is to setZero, however it first set 'a', keep 0 as it is
        # this only applies to dynamic programming language which does not restrict the element type in an array
        height = len(matrix)
        if(height ==0): return
        width = len(matrix[0])
        for i in range(height):
            for j in range(width):
                if matrix[i][j] == 0:
                    for tmp in range(height):
                        if matrix[tmp][j] != 0:
                            matrix[tmp][j] = 'a'
                    for tmp in range(width):
                        if matrix[i][tmp] != 0:
                            matrix[i][tmp] = 'a'
        for i in range(height):
            for j in range(width):
                if matrix[i][j] == 'a':
                    matrix[i][j] = 0
        return

        # [java] use a var to store first column, change others and change first column in the end
        void setZeroes(vector<vector<int> > &matrix) {
            int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

            for (int i = 0; i < rows; i++) {
                if (matrix[i][0] == 0) col0 = 0;
                for (int j = 1; j < cols; j++)
                    if (matrix[i][j] == 0)
                        matrix[i][0] = matrix[0][j] = 0;
            }

            for (int i = rows - 1; i >= 0; i--) {
                for (int j = cols - 1; j >= 1; j--)
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                if (col0 == 0) matrix[i][0] = 0;
            }
        }

def myprint(m):
    for i in range(len(m)):
        for j in range(len(m[i])):
            print m[i][j],
        print

s = Solution()
m = [
    [1, 2, 0],
    [0, 1, 2],
    [2, 2, 2]
]
s.setZeroes(m)
myprint(m)
