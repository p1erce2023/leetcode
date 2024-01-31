class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 24ms
        s, x = 0, n
        while x:
            x = x // 5
            s += x
        return s

        # 40ms
        s, x = 0, 5
        while x <= n:
            s += n // x
            x *= 5
        return s


s = Solution()
x = 1
for i in range(1, 31):
    x *= i
    print(i, x, s.trailingZeroes(i))
