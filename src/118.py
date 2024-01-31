class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        x = [[1], [1, 1]]
        if numRows <= 0:
            return []
        elif numRows == 1:
            return [x[0]]
        else:
            for i in xrange(2, numRows):
                row = [1] * (i + 1)
                idx = i >> 1 + 1
                for j in xrange(1, idx):
                    row[j] = x[i - 1][j - 1] + x[i - 1][j]
                for j in xrange(1, idx):  # symmetry
                    row[-j - 1] = row[j]
                x.append(row)
            return x

s = Solution()
print s.generate(5)
