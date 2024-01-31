class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m, n = len(board), len(board[0])
        # flag boundary
        f = [[1] * (n + 2)] + [[0] * (n + 2) for _ in xrange(m)] + [[1] * (n + 2)]
        for i in xrange(1, 1 + m):
            f[i][0] = f[i][-1] = 1
        s = [(1, j + 1) for j in xrange(n) if board[0][j] == 'O'] + \
            [(m, j + 1) for j in xrange(n) if board[-1][j] == 'O'] + \
            [(i + 1, 1) for i in xrange(m) if board[i][0] == 'O'] + \
            [(i + 1, n) for i in xrange(m) if board[i][-1] == 'O']
        x, y = -1, -1
        while s:
            x, y = s.pop()
            f[x][y] = 1
            if not f[x - 1][y] and board[x - 2][y - 1] == 'O':
                s.append((x - 1, y))
            if not f[x + 1][y] and board[x][y - 1] == 'O':
                s.append((x + 1, y))
            if not f[x][y - 1] and board[x - 1][y - 2] == 'O':
                s.append((x, y - 1))
            if not f[x][y + 1] and board[x - 1][y] == 'O':
                s.append((x, y + 1))
        for i in xrange(m):
            for j in xrange(n):
                if not f[i + 1][j + 1]:
                    board[i][j] = 'X'
        return


s = Solution()
board = [['X', 'X', 'O', 'X', 'X'],
         ['X', 'O', 'O', 'X', 'X'],
         ['X', 'X', 'X', 'O', 'O'],
         ['X', 'O', 'O', 'X', 'X'],
         ['X', 'X', 'X', 'X', 'X']]
s.solve(board)
for _board in board:
    print _board
