class Solution:
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        x = [[4, 6], [6, 8], [7, 9], [4, 8], [3, 9, 0], [], [1, 7, 0], [2, 6], [1, 3], [2, 4]]
        a = [1] * 10
        if N == 1:
            return 10
        n = N - 1
        m = 10 ** 9 + 7
        while n:
            b = [0] * 10
            for i in range(10):
                for j in x[i]:
                    b[j] += a[i] % m
            n -= 1
            a = b[:]
        return sum(a) % m


s = Solution()
# print(s.knightDialer(1))
# print(s.knightDialer(2))
# print(s.knightDialer(3))
# print(s.knightDialer(4))
# print(s.knightDialer(5))
print(s.knightDialer(161))  # 533302150
