class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        # pythonic!
        row = [1]
        for i in range(1, rowIndex + 1):
            row = list(map(lambda x, y: x + y, [0] + row, row + [0]))
        return row

        # O(k) extra space, symmetry
        if rowIndex < 0:
            return []
        row = [1]
        for i in xrange(1, rowIndex + 1):
            idx = i / 2 + 1
            for j in xrange(1, idx):
                row[j] += row[-j]
                row[-j] = row[j]
            row.append(1)
        return row

        # combination formula, slow
        if rowIndex < 0:
            return []
        row = [1]
        for i in xrange(1, rowIndex / 2 + 1):
            row[i] = row[-i - 1] = row[i - 1] / i * (rowIndex + 1 - i)
        return row

s = Solution()
# print s.getRow(4)
for i in xrange(8):
    print s.getRow(i)
