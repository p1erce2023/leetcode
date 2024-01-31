class Solution:
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        n = len(S)
        x = 1
        m = 10 ** 9 + 7
        last = {}
        for i in range(n):
            y = x
            x = ((x << 1) - last.get(S[i], 0)) % m
            last[S[i]] = y
        return (x - 1) % m


s = Solution()
print(s.distinctSubseqII("abc"))
print(s.distinctSubseqII("aba"))
print(s.distinctSubseqII("aaa"))
