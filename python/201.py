class Solution:
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # print(bin(m), bin(n))

        # x = m
        # for y in range(m, n + 1):
        #     x &= y
        #     if not x:
        #         return 0
        # return x

        # refer to others' solution
        while m < n:
            n = n & (n - 1)
        return n

        # find the right most 1 and set it to 0, slow
        x = m
        while x:
            y = x & -x
            if y + x <= n:
                x &= -(y << 1)
            else:
                return x
        return 0


s = Solution()
print(s.rangeBitwiseAnd(3, 3))
print(s.rangeBitwiseAnd(5, 7))
print(s.rangeBitwiseAnd(37, 39))
print(s.rangeBitwiseAnd(37, 40))
print(s.rangeBitwiseAnd(37, 64))
print(s.rangeBitwiseAnd(600000000, 2147483645))
print(s.rangeBitwiseAnd(45, 54))
