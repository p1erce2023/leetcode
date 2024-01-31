class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            return 1.0 / self.myPow(x, -n)
        elif not n:
            return 1
        if n == 1:
            return x
        elif n == 2:
            return x * x
        else:
            t = self.myPow(x, int(n/2))
            if n % 2:
                return t * t * x
            else:
                return t * t

s = Solution()
print s.myPow(2, 0)
print s.myPow(4, -2)
print s.myPow(1, 5)
print s.myPow(-1, 3)
print s.myPow(0, 4)
print s.myPow(-1, 6)
print s.myPow(2, 5)
print s.myPow(1.5, 5)
