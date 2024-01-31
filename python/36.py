class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        def valid9(s):
            nset, nlen = set(), 0
            for c in s:
                if c != '.':
                    nset.add(c)
                    nlen += 1
            if len(nset) == nlen:
                return True
            else:
                return False

        for row in board:
            if not valid9(row):
                return False

        boardT = [[x[i] for x in board] for i in range(9)]
        for column in boardT:
            if not valid9(column):
                return False

        boardS = [board[i][j:j+3]+board[i+1][j:j+3]+board[i+2][j:j+3]
                    for i in range(0, 9, 3) for j in range(0, 9, 3)]
        for room in boardS:
            if not valid9(room):
                return False

        return True

s = Solution()
print s.isValidSudoku([".87654321","2........","3........","4........","5........","6........","7........","8........","9........"])