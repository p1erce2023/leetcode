class Solution:
    # @param {integer} dividend
    # @param {integer} divisor
    # @return {integer}
    def divide(self, dividend, divisor):
        if not divisor or dividend == -2147483648 and divisor == -1:
            return 2147483647
        
        if not dividend:
            return 0
        
        if dividend > 0:
            if divisor > 0:
                sign = 1
            else:
                sign = -1
                divisor = -divisor    
        else:
            if divisor > 0:
                sign = -1
                dividend = -dividend
            else:
                sign = 1
                dividend, divisor = -dividend, -divisor

        Q = 1
        left, div, v = dividend, divisor, 0
        while left >= divisor:
            left -= div
            v += Q 
            Q += Q
            div += div
            if left < div:
                div = divisor
                Q = 1

        # res = dividend
        # v = 0
        # while 1:
        #     c, d, res = 1, divisor, res-divisor
        #     while res >= 0:
        #         v += c
        #         c += c
        #         d += d
        #         res -= d
        #     res += d
        #     if c == 1:
        #         break

        if sign == 1:
            return v
        else:
            return -v


s = Solution()
print s.divide(1, 0)
print s.divide(1, 2)
print s.divide(3, 1)
print s.divide(5, 2)
print s.divide(6, 2)
print s.divide(-6, 2)
print s.divide(-7, 2)
print s.divide(8, -2)
print s.divide(8, -3)
print s.divide(-8, -4)
print s.divide(-8, -3)
print s.divide(-8, -9)
print s.divide(-8, -8)
print s.divide(-2147483648, -1)
