class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        # top, 68ms
        if not s:
            return 0
        k = []
        l = [0] * len(s)
        for i, c in enumerate(s):
            if c == "(":
                k.append(i)
            else:
                if k:
                    t = k.pop()
                    l[i] = i - t + 1
                    if t:
                        l[i] += l[t - 1]
        # print l
        return max(l)

        # script 1, 88ms
        n = len(s)
        d = [0] * (n + 1)  # indegree and outdegree
        l = [0] * (n + 1)  # valid length ending by i and has i
        for i, c in enumerate(s):
            if c == '(':
                if d[i] >= 0:
                    d[i + 1] = d[i] + 1
                else:
                    d[i + 1] = 1
            else:
                if d[i] > 0:
                    d[i + 1] = d[i] - 1
                    if i-1 and s[i-1] == "(":
                        l[i + 1] = max(l[i] + 2, l[i - 1] + 2)
                    else:
                        l[i + 1] = l[i] + 2
                    
                    if i + 1 > l[i+1]:
                        l[i + 1] += l[i + 1 - l[i+1]]
                else:
                    d[i + 1] = -1
        
        # print d[1:], l[1:]

        return max(l)
    



s = Solution()
print s.longestValidParentheses("()(())(((((((())))))))")  # 22
print s.longestValidParentheses("()(())")  # 6
print s.longestValidParentheses("()()(")  # 4
print s.longestValidParentheses("()(()")  # 2
print s.longestValidParentheses(")()))))(())")  # 4
print s.longestValidParentheses(")()())")  # 4
print s.longestValidParentheses("(()")  # 2
print s.longestValidParentheses(")()())))")  # 4
print s.longestValidParentheses("()()())(")  # 6
print s.longestValidParentheses("((()())())")  # 10
print s.longestValidParentheses("")  # 0