class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        # dfs
        sol, n = [], len(word)
        row = len(board)
        if not row:
            return False
        col = len(board[0])
        for i in xrange(row):
            for j in xrange(col):
                if board[i][j] == word[0]:
                    sol.append(([(i, j)], 1))
        while sol:
            s, k = sol.pop()
            if k == n:
                return True
            node = s[-1]
            if 1 <= node[0] and (node[0]-1, node[1]) not in s and board[node[0]-1][node[1]] == word[k]:
                sol.append((s + [(node[0]-1, node[1])], k+1))
            if node[0]+1 < row and (node[0]+1, node[1]) not in s and board[node[0]+1][node[1]] == word[k]:
                sol.append((s + [(node[0]+1, node[1])], k+1))
            if 1 <= node[1] and (node[0], node[1]-1) not in s and board[node[0]][node[1]-1] == word[k]:
                sol.append((s + [(node[0], node[1]-1)], k+1))
            if node[1]+1 < col and (node[0], node[1]+1) not in s and board[node[0]][node[1]+1] == word[k]:
                sol.append((s + [(node[0], node[1]+1)], k+1))
        return False

s = Solution()
b = [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
]
print s.exist(b, "ABCCED")
print s.exist(b, "SEE")
print s.exist(b, "ABCB")
