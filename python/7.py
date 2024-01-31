class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        # beat 2/3 of all, 64ms
        if not x:
            return 0
        elif x > 0:
            r = self.reverse_p(x)
            if r > 2**31 - 1:
                return 0
            else:
                return r
        else:
            r =  -1 * self.reverse_p(-x)
            if r < -2**31:
                return 0
            else:
                return r

    def reverse_p(self, x):
        y = []
        while x:
            y.append(str(x % 10))
            x = x / 10
        return int(''.join(y))

s = Solution()
assert s.reverse(123) == 321
assert s.reverse(200) == 2
assert s.reverse(-123) == -321
assert s.reverse(0) == 0
assert s.reverse(1) == 1
assert s.reverse(1534236469) == 0