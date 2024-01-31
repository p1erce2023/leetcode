from math import sqrt

class Solution:  
    def func2(self, n):
        if n in self.cache:
            return self.cache[n]
        m = int(sqrt(n))
        if m * m == n:
            self.cache[n] = 1
            return 1
        # print(n, m)
        x = min(self.func2(n - i * i) for i in range(1,1+m)) + 1
        self.cache[n] = x
        return x  
    
    def numSquares2(self, n: int) -> int:
        # 1 4 9 16 25 36 49 64 81 100
        # 91 = 81 + 9 + 1
        # 64 + 25 = 89 = 81 + 4 + 4
        self.cache = {1:1, 2:2, 3:3}
        x = self.func2(n)
        # print(self.cache)
        return x

    def numSquares(self, n: int) -> int:
        if n < 4:
            return n
        dp = [0] * (n + 1)
        for i in range(1, 4):
            dp[i] = i
        for i in range(4, 1 + n):
            m = int(sqrt(i))
            if m * m == i:
                dp[i] = 1
                continue
            dp[i] = min(dp[i - j * j] for j in range(m, 1, -1)) + 1
        return dp[n]

s = Solution()

print(s.numSquares(12)) # 4 + 4 + 4

print(s.numSquares(13))