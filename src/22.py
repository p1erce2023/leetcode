class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        # 52ms, seems like the pop() function wastes a lot of time!
        rs = [["", 0, 0]]  # [string, left, right], this saves 12ms
        for i in xrange(2*n):
            rs_new = []
            for r in rs:
                if r[1] > r[2]:
                    if r[1] < n:
                        rs_new.append([r[0]+"(", r[1]+1, r[2]])
                    rs_new.append([r[0]+")", r[1], r[2]+1])
                else:
                    rs_new.append([r[0]+"(", r[1]+1, r[2]])
            rs = rs_new
        return [r[0] for r in rs]

        # 84ms, slow
        rs = [["", 0, 0]]  # [string, left-right, left]
        for i in xrange(2*n):
            rs_new = []
            while rs:
                r = rs.pop()
                if 0 < r[1]:
                    if r[2] < n:
                        rs_new.append([r[0]+"(", r[1]+1, r[2]+1])
                    rs_new.append([r[0]+")", r[1]-1, r[2]])
                else:
                    rs_new.append([r[0]+"(", r[1]+1, r[2]+1])
            rs = rs_new
        return [r[0] for r in rs]


s = Solution()
# print s.generateParenthesis(3)
# print s.generateParenthesis(2)
assert sorted(s.generateParenthesis(3)) == sorted(["((()))", "(()())", "(())()", "()(())", "()()()"])
assert sorted(s.generateParenthesis(2)) == sorted(["(())", "()()"])