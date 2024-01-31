class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        if not tokens:
            return 0
        op = {'+', '-', '*', '/'}
        s = []
        for t in tokens:
            if t in op:
                a = s.pop()
                b = s.pop()
                # OJ use python 2.7, result of 6/-132 is different in python2.7 or python 3.6
                s.append(str(int(eval(b + '.0' + t + a))))
            else:
                s.append(t)
        return int(s[0])


s = Solution()
print(s.evalRPN(['2', '1', '+', '3', '*']))
print(s.evalRPN(['4', '13', '5', '/', '+']))
print(s.evalRPN(['0', '3', '/']))
print(s.evalRPN(['10', '6', '9', '3', '+', '-11', '*', '/', '*', '17', '+', '5', '+']))
