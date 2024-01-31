class Solution:
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        这个dp想的很快
        """
        minA = A[0][:]
        n = len(A)
        i = 1
        while i < n:
            minB = [0] * n
            for j in range(1, n - 1):
                minB[j] = min(minA[j-1], minA[j], minA[j+1]) + A[i][j]
            minB[0] = min(minA[0], minA[1]) + A[i][0]
            minB[n - 1] = min(minA[n - 2], minA[n - 1]) + A[i][n - 1]
            minA = minB[:]
            i += 1
        return min(minA)


s = Solution()
print(s.minFallingPathSum([[1,2,3],[4,5,6],[7,8,9]]))
