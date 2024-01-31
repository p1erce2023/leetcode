import math
import random
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        # Newton's iteration
        # https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
        # compared to binary search, which is faster?
        r = x
        while r * r > x:
            r = (r + x/r) >> 1
        return r

        # binary search
        if not x:
            return 0
        s = (len(str(x)) - 1) / 2
        st, ed = 10**s, 10**(s+1)
        while st < ed:
            mid = (st & ed) + ((st ^ ed) >> 1)
            t = mid * mid
            if t == x:
                return mid
            elif t > x:
                ed = mid - 1
            else:
                st = mid + 1
        if st * st > x:
            return st - 1
        else:
            return st

s = Solution()
print s.mySqrt(0)
print s.mySqrt(3)

# for _ in range(10000):
t = random.randint(0, 1000000000)
# print t, s.mySqrt(t), int(math.sqrt(t))
assert s.mySqrt(t) == int(math.sqrt(t))
