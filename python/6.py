class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        # average 132ms
        if numRows == 1:
            return s
        re = [[] for _ in xrange(numRows)]
        i = 0
        for c in s:
            re[i].append(c)
            if i == numRows - 1:
                direction = -1
            elif not i:
                direction = 1
            i += direction
        return ''.join(''.join(r) for r in re)


s = Solution()

assert s.convert("ABC", 1) == "ABC"
assert s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR"
