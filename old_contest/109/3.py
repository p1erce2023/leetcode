class Solution:
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        n = len(A)
        m = len(A[0])
        B = [[0] * (m + 2) for _ in range(n + 2)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                B[i][j] = A[i - 1][j - 1]
        n += 1
        m += 1
        d1 = set()
        q = []
        for i in range(1, n):
            for j in range(1, m):
                if B[i][j]:
                    q.append((i, j))
                    break
            if q:
                break
        while q:
            i, j = q.pop()
            if (i, j) in d1:
                continue
            d1.add((i, j))
            B[i][j] = 2
            if B[i-1][j]:
                q.append((i-1, j))
            if B[i][j-1]:
                q.append((i, j-1))
            if B[i][j+1]:
                q.append((i, j+1))
            if B[i+1][j]:
                q.append((i+1, j))
        x = 0
        while 1:
            expand = set()
            for i, j in d1:
                if i > 1:
                    if B[i-1][j] == 1:
                        return x
                    else:
                        expand.add((i-1, j))
                if j > 1:
                    if B[i][j-1] == 1:
                        return x
                    else:
                        expand.add((i, j-1))
                if j < m:
                    if B[i][j + 1] == 1:
                        return x
                    else:
                        expand.add((i, j+1))
                if i < n:
                    if B[i+1][j] == 1:
                        return x
                    else:
                        expand.add((i+1, j))
            x += 1
            d1.update(expand)


s = Solution()
print(s.shortestBridge([[0,1],[1,0]]))  # 1
print(s.shortestBridge([[0,1,0],[0,0,0],[0,0,1]]))  # 2
print(s.shortestBridge([[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]))  # 1
print(s.shortestBridge([
    [0,1,0,1,0],
    [0,1,1,1,1],
    [0,0,0,0,1],
    [0,0,0,0,0],
    [1,0,0,0,1],
    [1,1,1,1,1],
]))  # 2
