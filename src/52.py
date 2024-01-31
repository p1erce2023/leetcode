class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        # other script, smart valid function
        # when (x, y) is occupied, all y, (x + y) and (x - y) should not repeat
        def __dfs(arg):
            if arg[4]==arg[5]:
                arg[0]+=1
            else:
                for i in range(arg[5]):
                    if not(arg[1][i] or arg[2][i+arg[4]] or arg[3][i-arg[4]+arg[5]-1]):
                        arg[1][i]=True
                        arg[2][i+arg[4]]=True
                        arg[3][i-arg[4]+arg[5]-1]=True
                        arg[4]+=1
                        __dfs(arg)
                        arg[4]-=1
                        arg[1][i]=False
                        arg[2][i+arg[4]]=False
                        arg[3][i-arg[4]+arg[5]-1]=False

        arg=[0,[False]*n,[False]*(2*n-1),[False]*(2*n-1),0,n]
        __dfs(arg)
        return arg[0]

        # script 1: directly copy from Problem 51
        def valid(row, col, nodes):
            for node in nodes:
                if node[0] == row or node[1] == col or abs(node[0] - row) == abs(node[1] - col):
                    return False
            return True

        def p(row, n, nodes, flag):
            results = 0
            if row == n:
                if flag:
                    return 2
                else:
                    return 1

            for i in xrange(n):
                if valid(row, i, nodes):
                    # below three line, key point in backtracking
                    nodes.append([row, i])
                    results += p(row + 1, n, nodes, flag)
                    nodes.pop()
            return results

        if n == 1:
            return 1
        results = 0
        for i in xrange(n / 2):  # use left-right mirror-symmetry
            nodes = [[0, i]]
            results += p(1, n, nodes, True)
        if n % 2:
            nodes = [[0, n / 2]]
            results += p(1, n, nodes, False)
        return results

s = Solution()
print s.totalNQueens(1)
print s.totalNQueens(2)
print s.totalNQueens(3)
print s.totalNQueens(4)
print s.totalNQueens(5)
print s.totalNQueens(8)