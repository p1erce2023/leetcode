class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # actually, Fibonacci[n]
        if n < 3:
            return n
        a, b = 1, 2
        for i in xrange(2, n):
            a, b = b, a + b
        return b

        s = [0] * n
        s[0] = 1
        s[1] = 2
        for i in xrange(2, n):
            s[i] = s[i-1] + s[i-2]
        return s[-1]
