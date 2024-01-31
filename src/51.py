class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def valid(row, col, nodes):
            for node in nodes:
                if node[0] == row or node[1] == col or abs(node[0] - row) == abs(node[1] - col):
                    return False
            return True

        def p(row, n, nodes, results, flag):
            if row == n:
                board = [["."] * n for _ in xrange(n)]
                for node in nodes:
                    board[node[0]][node[1]] = 'Q'
                results.append([''.join(r) for r in board])
                if flag:
                    results.append([''.join(r[::-1]) for r in board])
                return

            for i in xrange(n):
                if valid(row, i, nodes):
                    # below three line, key point in backtracking
                    nodes.append([row, i])
                    p(row + 1, n, nodes, results, flag)
                    nodes.pop()
            return

        if n == 1:
            return [[0, 0]]
        results = []
        for i in xrange(n / 2):  # use left-right mirror-symmetry
            nodes = [[0, i]]
            p(1, n, nodes, results, True)
        if n % 2:
            nodes = [[0, n / 2]]
            p(1, n, nodes, results, False)
        return results


s = Solution()
print s.solveNQueens(1)
print s.solveNQueens(2)
print len(s.solveNQueens(8))
print s.solveNQueens(4)
print len(s.solveNQueens(5))
print sorted(s.solveNQueens(5)) == sorted([["Q....","..Q..","....Q",".Q...","...Q."],["Q....","...Q.",".Q...","....Q","..Q.."],[".Q...","...Q.","Q....","..Q..","....Q"],[".Q...","....Q","..Q..","Q....","...Q."],["..Q..","Q....","...Q.",".Q...","....Q"],["..Q..","....Q",".Q...","...Q.","Q...."],["...Q.","Q....","..Q..","....Q",".Q..."],["...Q.",".Q...","....Q","..Q..","Q...."],["....Q",".Q...","...Q.","Q....","..Q.."],["....Q","..Q..","Q....","...Q.",".Q..."]])
